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

    ProcessV2CSVTyreImpl::TimeStamp createTimeStamp()
    {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
        return std::string(buffer);
    }

    void createCSVFile(const ProcessV2CSVTyreImpl::TrackName &trackname,
                       const ProcessV2CSVTyreImpl::Lap lap,
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

    vector<string> getNames()
    {
        return {"time", "distance", "unfiltered_throttle",
                "unfiltered_brake", "unfiltered_steering",
                "unfiltered_clutch", "throttle",
                "brake", "steering", "clutch",
                "tyre_rps_fl", "tyre_rps_fr","tyre_rps_rl","tyre_rps_rr",
                "tyre_y_fl", "tyre_y_fr","tyre_y_rl","tyre_y_rr",
                "tyre_temp_fl", "tyre_temp_fr","tyre_temp_rl","tyre_temp_rr",
                "tyre_height_above_ground_fl", "tyre_height_above_ground_fr","tyre_height_above_ground_rl","tyre_height_above_ground_rr",
                "tyre_wear_fl", "tyre_wear_fr","tyre_wear_rl","tyre_wear_rr",
                "tyre_tread_temp_fl", "tyre_tread_temp_fr","tyre_tread_temp_rl","tyre_tread_temp_rr",
                "tyre_layer_temp_fl", "tyre_layer_temp_fr","tyre_layer_temp_rl","tyre_layer_temp_rr",
                "tyre_carcass_temp_fl", "tyre_carcass_temp_fr","tyre_carcass_temp_rl","tyre_carcass_temp_rr",
                "tyre_rim_temp_fl", "tyre_rim_temp_fr","tyre_rim_temp_rl","tyre_rim_temp_rr",
                "tyre_internal_air_temp_fl", "tyre_internal_air_temp_fr","tyre_internal_air_temp_rl","tyre_internal_air_temp_rr",
                "tyre_left_fl", "tyre_left_temp_fr","tyre_left_temp_rl","tyre_left_temp_rr",
                "tyre_center_temp_fl", "tyre_center_temp_fr","tyre_center_temp_rl","tyre_center_temp_rr",
                "tyre_right_temp_fl", "tyre_right_temp_fr","tyre_right_temp_rl","tyre_right_temp_rr",
                "wheel_local_position_y_fl", "wheel_local_position_y_fr","wheel_local_position_y_rl","wheel_local_position_y_rr",
                "air_pressure_fl", "air_pressure_fr","air_pressure_rl","air_pressure_rr"};
    
    }

    ProcessV2CSVTyreImpl::ProcessV2CSVTyreImpl()
        : data_{make_unique<TelemetryData>()}
    {
        data_->names = getNames();
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

            telemetry_.elements.push_back(p->tyre_rps().at(0));
            telemetry_.elements.push_back(p->tyre_rps().at(1));
            telemetry_.elements.push_back(p->tyre_rps().at(2));
            telemetry_.elements.push_back(p->tyre_rps().at(3));
            
            telemetry_.elements.push_back(p->tyre_y().at(0));
            telemetry_.elements.push_back(p->tyre_y().at(1));
            telemetry_.elements.push_back(p->tyre_y().at(2));
            telemetry_.elements.push_back(p->tyre_y().at(3));

            telemetry_.elements.push_back(p->tyre_temp().at(0));
            telemetry_.elements.push_back(p->tyre_temp().at(1));
            telemetry_.elements.push_back(p->tyre_temp().at(2));
            telemetry_.elements.push_back(p->tyre_temp().at(3));

            telemetry_.elements.push_back(p->tyre_height_above_ground().at(0));
            telemetry_.elements.push_back(p->tyre_height_above_ground().at(1));
            telemetry_.elements.push_back(p->tyre_height_above_ground().at(2));
            telemetry_.elements.push_back(p->tyre_height_above_ground().at(3));
            
            telemetry_.elements.push_back(p->tyre_wear().at(0));
            telemetry_.elements.push_back(p->tyre_wear().at(1));
            telemetry_.elements.push_back(p->tyre_wear().at(2));
            telemetry_.elements.push_back(p->tyre_wear().at(3));

            telemetry_.elements.push_back(p->tyre_tread_temp().at(0));
            telemetry_.elements.push_back(p->tyre_tread_temp().at(1));
            telemetry_.elements.push_back(p->tyre_tread_temp().at(2));
            telemetry_.elements.push_back(p->tyre_tread_temp().at(3));

            telemetry_.elements.push_back(p->tyre_layer_temp().at(0));
            telemetry_.elements.push_back(p->tyre_layer_temp().at(1));
            telemetry_.elements.push_back(p->tyre_layer_temp().at(2));
            telemetry_.elements.push_back(p->tyre_layer_temp().at(3));

            telemetry_.elements.push_back(p->tyre_carcass_temp().at(0));
            telemetry_.elements.push_back(p->tyre_carcass_temp().at(1));
            telemetry_.elements.push_back(p->tyre_carcass_temp().at(2));
            telemetry_.elements.push_back(p->tyre_carcass_temp().at(3));

            telemetry_.elements.push_back(p->tyre_rim_temp().at(0));
            telemetry_.elements.push_back(p->tyre_rim_temp().at(1));
            telemetry_.elements.push_back(p->tyre_rim_temp().at(2));
            telemetry_.elements.push_back(p->tyre_rim_temp().at(3));

            telemetry_.elements.push_back(p->tyre_internal_air_temp().at(0));
            telemetry_.elements.push_back(p->tyre_internal_air_temp().at(1));
            telemetry_.elements.push_back(p->tyre_internal_air_temp().at(2));
            telemetry_.elements.push_back(p->tyre_internal_air_temp().at(3));

            telemetry_.elements.push_back(p->tyre_temp_left().at(0));
            telemetry_.elements.push_back(p->tyre_temp_left().at(1));
            telemetry_.elements.push_back(p->tyre_temp_left().at(2));
            telemetry_.elements.push_back(p->tyre_temp_left().at(3));
            
            telemetry_.elements.push_back(p->tyre_temp_center().at(0));
            telemetry_.elements.push_back(p->tyre_temp_center().at(1));
            telemetry_.elements.push_back(p->tyre_temp_center().at(2));
            telemetry_.elements.push_back(p->tyre_temp_center().at(3));

            telemetry_.elements.push_back(p->tyre_temp_right().at(0));
            telemetry_.elements.push_back(p->tyre_temp_right().at(1));
            telemetry_.elements.push_back(p->tyre_temp_right().at(2));
            telemetry_.elements.push_back(p->tyre_temp_right().at(3));

            telemetry_.elements.push_back(p->wheel_local_position_y().at(0));
            telemetry_.elements.push_back(p->wheel_local_position_y().at(1));
            telemetry_.elements.push_back(p->wheel_local_position_y().at(2));
            telemetry_.elements.push_back(p->wheel_local_position_y().at(3));

            telemetry_.elements.push_back(p->air_pressure().at(0));
            telemetry_.elements.push_back(p->air_pressure().at(1));
            telemetry_.elements.push_back(p->air_pressure().at(2));
            telemetry_.elements.push_back(p->air_pressure().at(3));

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
                 { createCSVFile(name, lap, data); },
                 trackname_, currentlap_, move(data_));
        t.detach();

        data_ = make_unique<TelemetryData>();
        data_->names = getNames();
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