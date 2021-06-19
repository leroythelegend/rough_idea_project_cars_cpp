#include "../inc/processv2csvtelemetryimpl.h"
#include "../inc/packetracedata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/csvencoder.h"

#include <vector>
#include <thread>

using namespace std;

namespace pcars
{

    ProcessV2CSVTelemetryImpl::TimeStamp createTimeStamp()
    {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
        return std::string(buffer);
    }

    void createCSVFile(const ProcessV2CSVTelemetryImpl::TrackName &trackname,
                       const ProcessV2CSVTelemetryImpl::Lap lap,
                       const unique_ptr<TelemetryData> &data)
    {
        CSVEncoder encoder(trackname +
                           " lap " +
                           to_string(lap) +
                           " " +
                           createTimeStamp() +
                           ".csv");
        encoder.encode(data);
    }

    ProcessV2CSVTelemetryImpl::ProcessV2CSVTelemetryImpl()
        : data_{make_unique<TelemetryData>()} {}

    ProcessV2CSVTelemetryImpl::TrackName ProcessV2CSVTelemetryImpl::getTrackName(Packet::Ptr &packet)
    {
        TrackName result;
        if (packet->type() == PACKETTYPE::PACKETRACEDATA)
        {
            PacketRaceData *p = dynamic_cast<PacketRaceData *>(packet.get());
            result = p->track_location() + "-" + p->track_variation();
        }
        return result;
    }

    void ProcessV2CSVTelemetryImpl::updateTimingData(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            currenttime_.time = p->partcipants().at(p->local_participant_index()).current_time();
            currenttime_.distance = p->partcipants().at(p->local_participant_index()).current_lap_distance();
            currenttime_.tick = p->tick_count();
        }
    }

    void ProcessV2CSVTelemetryImpl::updateNextLap(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());
            nextlap_ = p->partcipants().at(p->local_participant_index()).current_lap();
        }
    }

    void ProcessV2CSVTelemetryImpl::updateRaceState(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            state_ = p->partcipants().at(p->local_participant_index()).race_state();
        }
    }

    void ProcessV2CSVTelemetryImpl::updateTrackName(Packet::Ptr &packet)
    {
        if (!havetrackname_)
        {
            trackname_ = getTrackName(packet);
            if (!trackname_.empty())
            {
                havetrackname_ = true;
            }
        }
    }

    void ProcessV2CSVTelemetryImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
        {
            PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
            telemetry_.tick = p->tick_count();
            telemetry_.rpm = p->rpm();
            telemetry_.unfilteredbrake = p->unfiltered_brake();
        }
    }


    void ProcessV2CSVTelemetryImpl::updateLapWithCapturedTelemetry()
    {
        if (telemetry_.tick == currenttime_.tick && nextlap_ == currentlap_)
        {
            vector<float> row;
            row.push_back(currenttime_.time);
            row.push_back(currenttime_.distance);
            row.push_back(telemetry_.rpm);
            row.push_back(telemetry_.unfilteredbrake);
            data_->telemetry.push_back(row);
        }
    }

    void ProcessV2CSVTelemetryImpl::updateCurrentLap()
    {
        currentlap_ = nextlap_;
    }

    void ProcessV2CSVTelemetryImpl::writeCapturedTelemetryToCSV()
    {
        thread t([](TrackName name, Lap lap, unique_ptr<TelemetryData> data)
                 { createCSVFile(name, lap, data); },
                 trackname_, currentlap_, move(data_));
        t.detach();
        data_ = make_unique<TelemetryData>();
    }

    bool ProcessV2CSVTelemetryImpl::isFirstOutLapFinshed() const
    {
        return state_ != 9 && !trackname_.empty();
    }

    bool ProcessV2CSVTelemetryImpl::isThisANewLap() const
    {
        return nextlap_ != currentlap_;
    }

    bool ProcessV2CSVTelemetryImpl::isThisTheFirstLap() const
    {
        return currentlap_ == NOTALAP;
    }

    bool ProcessV2CSVTelemetryImpl::isTelemetryEmpty() const
    {
        return data_->telemetry.empty();
    }

    void ProcessV2CSVTelemetryImpl::reset()
    {
        havetrackname_ = false;
        trackname_.clear();
        state_ = 0;
        currentlap_ = NOTALAP;
        nextlap_ = 0;
        currenttime_.time = -1;
        currenttime_.tick = 0;
        currenttime_.distance = 0;
        telemetry_.rpm = 0;
        telemetry_.unfilteredbrake = 0;
        telemetry_.tick = 1;
        data_->telemetry.clear();
    }
}