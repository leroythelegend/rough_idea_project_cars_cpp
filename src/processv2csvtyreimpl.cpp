#include "../inc/processv2csvtyreimpl.h"
#include "../inc/packetracedata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/csvencoder.h"

#include <vector>
#include <thread>

using namespace std;

namespace pcars
{

    ProcessV2CSVTyreImpl::TimeStamp createTimeStampTyres()
    {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
        return std::string(buffer);
    }

    void createCSVFileTyres(const ProcessV2CSVTyreImpl::TrackName &trackname,
                       const ProcessV2CSVTyreImpl::Lap lap,
                       const unique_ptr<TelemetryData> &data)
    {
        CSVEncoder encoder(trackname +
                           " lap " +
                           to_string(lap) +
                           " " +
                           " tyre " +
                           createTimeStampTyres() +
                           ".csv");
        encoder.encode(data);
    }

    vector<string> getNamesTyre()
    {
        return {"time", "distance", "unfiltered_throttle",
                "unfiltered_brake", "unfiltered_steering",
                "unfiltered_clutch", "throttle",
                "brake", "steering", "clutch",
                "ride_height_fl","ride_height_fr","ride_height_rl","ride_heightrr"};
    }

    ProcessV2CSVTyreImpl::ProcessV2CSVTyreImpl()
        : data_{make_unique<TelemetryData>()}
    {
        data_->names = getNamesTyre();
    }

    ProcessV2CSVTyreImpl::TrackName ProcessV2CSVTyreImpl::getTrackName(Packet::Ptr &packet)
    {
        TrackName result;
        if (packet->type() == PACKETTYPE::PACKETRACEDATA)
        {
            PacketRaceData *p = dynamic_cast<PacketRaceData *>(packet.get());
            result = p->track_location() + "-" + p->track_variation();
        }
        return result;
    }

    void ProcessV2CSVTyreImpl::updateTimingData(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            currenttime_.time = p->partcipants().at(p->local_participant_index()).current_time();
            currenttime_.distance = p->partcipants().at(p->local_participant_index()).current_lap_distance();
            currenttime_.tick = p->tick_count();
        }
    }

    void ProcessV2CSVTyreImpl::updateNextLap(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());
            nextlap_ = p->partcipants().at(p->local_participant_index()).current_lap();
        }
    }

    void ProcessV2CSVTyreImpl::updateRaceState(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            state_ = p->partcipants().at(p->local_participant_index()).race_state();
        }
    }

    void ProcessV2CSVTyreImpl::updateTrackName(Packet::Ptr &packet)
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

    void ProcessV2CSVTyreImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
        {
            PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
            telemetry_.tick = p->tick_count();

            telemetry_.elements.clear();
            telemetry_.elements.push_back(p->unfiltered_throttle());
            telemetry_.elements.push_back(p->unfiltered_brake());
            telemetry_.elements.push_back(p->unfiltered_steering());
            telemetry_.elements.push_back(p->unfiltered_clutch());
            telemetry_.elements.push_back(p->throttle());
            telemetry_.elements.push_back(p->brake());
            telemetry_.elements.push_back(p->steering());
            telemetry_.elements.push_back(p->clutch());

            telemetry_.elements.push_back(p->ride_height().at(0));
            telemetry_.elements.push_back(p->ride_height().at(1));
            telemetry_.elements.push_back(p->ride_height().at(2));
            telemetry_.elements.push_back(p->ride_height().at(3));
        }
    }

    void ProcessV2CSVTyreImpl::updateLapWithCapturedTelemetry()
    {
        if (telemetry_.tick == currenttime_.tick &&
            nextlap_ == currentlap_ &&
            !telemetry_.elements.empty())
        {
            vector<float> row;
            row.push_back(currenttime_.time);
            row.push_back(currenttime_.distance);
            for (auto element : telemetry_.elements)
            {
                row.push_back(element);
            }
            data_->telemetry.push_back(row);
        }
    }

    void ProcessV2CSVTyreImpl::updateCurrentLap()
    {
        currentlap_ = nextlap_;
    }

    void ProcessV2CSVTyreImpl::writeCapturedTelemetryToCSV()
    {
        thread t([](TrackName name, Lap lap, unique_ptr<TelemetryData> data)
                 { createCSVFileTyres(name, lap, data); },
                 trackname_, currentlap_, move(data_));
        t.detach();

        data_ = make_unique<TelemetryData>();
        data_->names = getNamesTyre();
    }

    bool ProcessV2CSVTyreImpl::isFirstOutLapFinshed() const
    {
        return state_ != 9 && !trackname_.empty();
    }

    bool ProcessV2CSVTyreImpl::isThisANewLap() const
    {
        return nextlap_ != currentlap_;
    }

    bool ProcessV2CSVTyreImpl::isThisTheFirstLap() const
    {
        return currentlap_ == NOTALAP;
    }

    bool ProcessV2CSVTyreImpl::isTelemetryEmpty() const
    {
        return data_->telemetry.empty();
    }

    void ProcessV2CSVTyreImpl::reset()
    {
        havetrackname_ = false;
        trackname_.clear();
        state_ = 0;
        currentlap_ = NOTALAP;
        nextlap_ = 0;
        currenttime_.time = -1;
        currenttime_.tick = 0;
        currenttime_.distance = 0;
        telemetry_.elements.clear();
        data_->telemetry.clear();
    }
}