#include "../inc/processv2csvtyreimpl.h"
#include "../inc/packettelemetrydata.h"

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names tyrenames = {"time", "distance", 
                                         "tyre_rps_fl", "tyre_rps_fr", "tyre_rps_rl", "tyre_rps_rr",
                                         "tyre_y_fl", "tyre_y_fr", "tyre_y_rl", "tyre_y_rr",
                                         "tyre_temp_fl", "tyre_temp_fr", "tyre_temp_rl", "tyre_temp_rr",
                                         "tyre_height_above_ground_fl", "tyre_height_above_ground_fr", "tyre_height_above_ground_rl", "tyre_height_above_ground_rr",
                                         "tyre_wear_fl", "tyre_wear_fr", "tyre_wear_rl", "tyre_wear_rr",
                                         "tyre_tread_temp_fl", "tyre_tread_temp_fr", "tyre_tread_temp_rl", "tyre_tread_temp_rr",
                                         "tyre_layer_temp_fl", "tyre_layer_temp_fr", "tyre_layer_temp_rl", "tyre_layer_temp_rr",
                                         "tyre_carcass_temp_fl", "tyre_carcass_temp_fr", "tyre_carcass_temp_rl", "tyre_carcass_temp_rr",
                                         "tyre_rim_temp_fl", "tyre_rim_temp_fr", "tyre_rim_temp_rl", "tyre_rim_temp_rr",
                                         "tyre_internal_air_temp_fl", "tyre_internal_air_temp_fr", "tyre_internal_air_temp_rl", "tyre_internal_air_temp_rr",
                                         "tyre_left_fl", "tyre_left_temp_fr", "tyre_left_temp_rl", "tyre_left_temp_rr",
                                         "tyre_center_temp_fl", "tyre_center_temp_fr", "tyre_center_temp_rl", "tyre_center_temp_rr",
                                         "tyre_right_temp_fl", "tyre_right_temp_fr", "tyre_right_temp_rl", "tyre_right_temp_rr",
                                         "wheel_local_position_y_fl", "wheel_local_position_y_fr", "wheel_local_position_y_rl", "wheel_local_position_y_rr",
                                         "air_pressure_fl", "air_pressure_fr", "air_pressure_rl", "air_pressure_rr",
                                         "brake_temp_celsius_fl", "brake_temp_celsius_fr", "brake_temp_celsius_rl", "brake_temp_celsius_rr"};





    ProcessV2CSVTyreImpl::ProcessV2CSVTyreImpl()
        : ProcessV2CSVImpl("tyres", tyrenames) {}

    void ProcessV2CSVTyreImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
        {
            PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
            telemetry_.tick = p->tick_count();

            telemetry_.elements.clear();

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

            telemetry_.elements.push_back(p->brake_temp_celsius().at(0));
            telemetry_.elements.push_back(p->brake_temp_celsius().at(1));
            telemetry_.elements.push_back(p->brake_temp_celsius().at(2));
            telemetry_.elements.push_back(p->brake_temp_celsius().at(3));



            
        }
    }
}
