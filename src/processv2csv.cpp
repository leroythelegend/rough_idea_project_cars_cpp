#include "../inc/processv2csv.h"

#include <time.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <utility>

#include "../inc/packettelemetrydatav1.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/packetparticipantinfostrings.h"
#include "../inc/packetparticipantinfostringsadditional.h"
#include "../inc/packetracedata.h"
#include "../inc/packetparticipantsdata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packetgamestate.h"
#include "../inc/packettimestatsdata.h"
#include "../inc/packetparticipantvehiclenamesdata.h"
#include "../inc/packetvehicleclassnamesdata.h"
#include "../inc/csvencoder.h"

using namespace std;

namespace pcars
{

    ProcessV2CSV::ProcessV2CSV()
        : data_{make_unique<TelemetryData>()}
    {
    }

    void ProcessV2CSV::playing(PacketPtr &packet)
    {
        updateCurrentLap(packet);
        updateTimingData(packet);
        updateRaceState(packet);
        updateTrackName(packet);

        if (isFirstOutLapFinshed())
        {
            if (isThisANewLap())
            {
                if (isThisTheFirstLap())
                {
                    currentlap_ = nextlap_;
                }
                else
                {
                    writeCapturedTelemetryToCSV();
                    currentlap_ = nextlap_;
                }
            }

            updateTelemetry(packet);
            updateLapWithCapturedTelemetry();
        }
    }

    void ProcessV2CSV::rest(PacketPtr &)
    {
        havetrackname_ = false;
        trackname_.clear();
        state_ = 0;
        currentlap_ = NOTALAP;
        nextlap_ = 0;
        currenttime_.time = -1;
        currenttime_.tick = 0;
        currenttime_.distance = 0;
        rpm_.rpm = 0;
        rpm_.tick = 1;
        data_->telemetry.clear();
    }

    void ProcessV2CSV::menu(PacketPtr &packet)
    {
        updateTrackName(packet);

        // last lap jumps to menu
        // so if there is any data
        // left write to csv file.
        if (!data_->telemetry.empty())
        {
            writeCapturedTelemetryToCSV();
        }
    }

    void ProcessV2CSV::updateTimingData(PacketPtr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            currenttime_.time = p->partcipants().at(p->local_participant_index()).current_time();
            currenttime_.distance = p->partcipants().at(p->local_participant_index()).current_lap_distance();
            currenttime_.tick = p->tick_count();
        }
    }

    void ProcessV2CSV::updateCurrentLap(PacketPtr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());
            nextlap_ = p->partcipants().at(p->local_participant_index()).current_lap();
        }
    }

    ProcessV2CSV::TrackName ProcessV2CSV::getTrackName(PacketPtr &packet)
    {
        TrackName result;
        if (packet->type() == PACKETTYPE::PACKETRACEDATA)
        {
            PacketRaceData *p = dynamic_cast<PacketRaceData *>(packet.get());
            result = p->track_location() + "-" + p->track_variation();
        }
        return result;
    }

    void ProcessV2CSV::updateRaceState(PacketPtr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            state_ = p->partcipants().at(p->local_participant_index()).race_state();
        }
    }

    void ProcessV2CSV::updateTrackName(PacketPtr &packet)
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

    void ProcessV2CSV::updateTelemetry(PacketPtr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
        {
            PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
            rpm_.tick = p->tick_count();
            rpm_.rpm = p->rpm();
        }
    }

    void ProcessV2CSV::updateLapWithCapturedTelemetry()
    {

        if (rpm_.tick == currenttime_.tick && nextlap_ == currentlap_)
        {
            vector<float> row;
            row.push_back(currenttime_.time);
            row.push_back(currenttime_.distance);
            row.push_back(rpm_.rpm);
            data_->telemetry.push_back(row);
        }
    }

    ProcessV2CSV::TimeStamp createTimeStamp()
    {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
        return std::string(buffer);
    }

    void createCSVFile(const ProcessV2CSV::TrackName &trackname,
                       const ProcessV2CSV::Lap lap,
                       const unique_ptr<TelemetryData> &data)
    {
        CSVEncoder encoder(trackname +
                           " lap " +
                           to_string(lap) +
                           " " +
                           createTimeStamp() +
                           ".csv");
        encoder.encodeRPM(data);
    }

    void ProcessV2CSV::writeCapturedTelemetryToCSV()
    {
        thread t([](TrackName name, Lap lap, unique_ptr<TelemetryData> data)
                 { createCSVFile(name, lap, data); },
                 trackname_, currentlap_, move(data_));
        t.detach();
        data_ = make_unique<TelemetryData>();
    }

    bool ProcessV2CSV::isFirstOutLapFinshed()
    {
        return state_ != 9 && !trackname_.empty();
    }

    bool ProcessV2CSV::isThisANewLap()
    {
        return nextlap_ != currentlap_;
    }

    bool ProcessV2CSV::isThisTheFirstLap()
    {
        return currentlap_ == NOTALAP;
    }
}
