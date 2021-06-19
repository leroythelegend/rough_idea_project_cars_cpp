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

    ProcessV2CSV::ProcessV2CSV(const ProcessV2CSVImpl::Ptr &impl)
        : impl_{impl}
    {
    }

    void ProcessV2CSV::playing(PacketPtr &packet)
    {
        impl_->updateNextLap(packet);
        impl_->updateTimingData(packet);
        impl_->updateRaceState(packet);
        impl_->updateTrackName(packet);

        if (impl_->isFirstOutLapFinshed())
        {
            if (impl_->isThisANewLap())
            {
                if (impl_->isThisTheFirstLap())
                {
                    impl_->updateCurrentLap();
                }
                else
                {
                    impl_->writeCapturedTelemetryToCSV();
                    impl_->updateCurrentLap();
                }
            }

            impl_->updateTelemetry(packet);
            impl_->updateLapWithCapturedTelemetry();
        }
    }

    void ProcessV2CSV::reset(PacketPtr &)
    {
        // reset when not playing
        impl_->reset();
    }

    void ProcessV2CSV::menu(PacketPtr &packet)
    {
        impl_->updateTrackName(packet);

        // last lap jumps to menu
        // so if there is any data
        // left write to csv file.
        if (!impl_->isTelemetryEmpty())
        {
            impl_->writeCapturedTelemetryToCSV();
        }
    }

    // void ProcessV2CSV::updateTimingData(PacketPtr &packet)
    // {
    //     if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
    //     {
    //         PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

    //         currenttime_.time = p->partcipants().at(p->local_participant_index()).current_time();
    //         currenttime_.distance = p->partcipants().at(p->local_participant_index()).current_lap_distance();
    //         currenttime_.tick = p->tick_count();
    //     }
    // }

    // void ProcessV2CSV::updateCurrentLap(PacketPtr &packet)
    // {
    //     if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
    //     {
    //         PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());
    //         nextlap_ = p->partcipants().at(p->local_participant_index()).current_lap();
    //     }
    // }

    // ProcessV2CSV::TrackName ProcessV2CSV::getTrackName(PacketPtr &packet)
    // {
    //     TrackName result;
    //     if (packet->type() == PACKETTYPE::PACKETRACEDATA)
    //     {
    //         PacketRaceData *p = dynamic_cast<PacketRaceData *>(packet.get());
    //         result = p->track_location() + "-" + p->track_variation();
    //     }
    //     return result;
    // }

    // void ProcessV2CSV::updateRaceState(PacketPtr &packet)
    // {
    //     if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
    //     {
    //         PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

    //         state_ = p->partcipants().at(p->local_participant_index()).race_state();
    //     }
    // }

    // void ProcessV2CSV::updateTrackName(PacketPtr &packet)
    // {
    //     if (!havetrackname_)
    //     {
    //         trackname_ = getTrackName(packet);
    //         if (!trackname_.empty())
    //         {
    //             havetrackname_ = true;
    //         }
    //     }
    // }

    // void ProcessV2CSV::updateTelemetry(PacketPtr &packet)
    // {
    //     if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
    //     {
    //         PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
    //         rpm_.tick = p->tick_count();
    //         rpm_.rpm = p->rpm();
    //     }
    // }

    // void ProcessV2CSV::updateLapWithCapturedTelemetry()
    // {

    //     if (rpm_.tick == currenttime_.tick && nextlap_ == currentlap_)
    //     {
    //         vector<float> row;
    //         row.push_back(currenttime_.time);
    //         row.push_back(currenttime_.distance);
    //         row.push_back(rpm_.rpm);
    //         data_->telemetry.push_back(row);
    //     }
    // }

    // ProcessV2CSV::TimeStamp createTimeStamp()
    // {
    //     time_t rawtime;
    //     struct tm *timeinfo;
    //     char buffer[80];

    //     time(&rawtime);
    //     timeinfo = localtime(&rawtime);

    //     strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    //     return std::string(buffer);
    // }

    // void createCSVFile(const ProcessV2CSV::TrackName &trackname,
    //                    const ProcessV2CSV::Lap lap,
    //                    const unique_ptr<TelemetryData> &data)
    // {
    //     CSVEncoder encoder(trackname +
    //                        " lap " +
    //                        to_string(lap) +
    //                        " " +
    //                        createTimeStamp() +
    //                        ".csv");
    //     encoder.encodeRPM(data);
    // }

    // void ProcessV2CSV::writeCapturedTelemetryToCSV()
    // {
    //     thread t([](TrackName name, Lap lap, unique_ptr<TelemetryData> data)
    //              { createCSVFile(name, lap, data); },
    //              trackname_, currentlap_, move(data_));
    //     t.detach();
    //     data_ = make_unique<TelemetryData>();
    // }

    // bool ProcessV2CSV::isFirstOutLapFinshed()
    // {
    //     return state_ != 9 && !trackname_.empty();
    // }

    // bool ProcessV2CSV::isThisANewLap()
    // {
    //     return nextlap_ != currentlap_;
    // }

    // bool ProcessV2CSV::isThisTheFirstLap()
    // {
    //     return currentlap_ == NOTALAP;
    // }
}
