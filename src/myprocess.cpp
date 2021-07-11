#include "../inc/myprocess.h"

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

#include <iostream>

using namespace std;

namespace pcars
{

    void MyProcessV1::playing(Packet::Ptr & packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1) {
            PacketTelemetryDataV1 * p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            participants_ = p->num_participants();

            cout << endl << "Telemetry Data " << endl << endl;
            cout << "Build Version                 : " << p->build_version()                 << endl;
            cout << "Sequence Number               : " << p->sequence_number()               << endl;
            cout << "Packet Type                   : " << p->packet_type()                   << endl;
            cout << "Session State                 : " << p->session_state()                 << endl;
            cout << "Game State                    : " << p->game_state()                    << endl;
            cout << "Viewed Participant Index      : " << p->viewed_participant_index()      << endl;
            cout << "Number of Participants        : " << p->num_participants()              << endl;
            cout << "Unfiltered Throttle           : " << p->unfiltered_throttle()           << endl;
            cout << "Unfiltered Brake              : " << p->unfiltered_brake()              << endl;
            cout << "Unfiltered Steering           : " << p->unfiltered_steering()           << endl;
            cout << "Unfiltered Clutch             : " << p->unfiltered_clutch()             << endl;
            cout << "Race State Flags              : " << p->race_state_flags()              << endl;
            cout << "Laps in Event                 : " << p->laps_in_event()                 << endl;
            cout << "Best Lap Time                 : " << p->best_lap_time()                 << endl;
            cout << "last Lap Time                 : " << p->last_lap_time()                 << endl;
            cout << "Current Time                  : " << p->current_time()                  << endl;
            cout << "Split Time Ahead              : " << p->split_time_ahead()              << endl;
            cout << "Split Time Behind             : " << p->split_time_behind()             << endl;
            cout << "Split Time                    : " << p->split_time()                    << endl;
            cout << "Event Time Remaining          : " << p->event_time_remaining()          << endl;
            cout << "Personal Fastest Lap Time     : " << p->personal_fastest_lap_time()     << endl;
            cout << "World Fastest Lap Time        : " << p->world_fastest_lap_time()        << endl;
            cout << "Current Sector1 Time          : " << p->current_sector1_time()          << endl;
            cout << "Current Sector2 Time          : " << p->current_sector2_time()          << endl;
            cout << "Current Sector3 Time          : " << p->current_sector3_time()          << endl;
            cout << "Fastest Sector1 Time          : " << p->fastest_sector1_time()          << endl;
            cout << "Fastest Sector2 Time          : " << p->fastest_sector2_time()          << endl;
            cout << "Fastest Sector3 Time          : " << p->fastest_sector3_time()          << endl;
            cout << "Personal Fastest Sector1 Time : " << p->personal_fastest_sector1_time() << endl;
            cout << "Personal Fastest Sector2 Time : " << p->personal_fastest_sector2_time() << endl;
            cout << "Personal Fastest Sector3 Time : " << p->personal_fastest_sector3_time() << endl;
            cout << "World Fastest Sector1 Time    : " << p->world_fastest_sector1_time()    << endl;
            cout << "World Fastest Sector2 Time    : " << p->world_fastest_sector2_time()    << endl;
            cout << "World Fastest Sector3 Time    : " << p->world_fastest_sector3_time()    << endl;
            cout << "Joy Pad                       : " << p->joy_pad()                       << endl;
            cout << "Flag Reason                   : " << p->flag_reason()                   << endl;
            cout << "Flag Colour                   : " << p->flag_colour()                   << endl;
            cout << "Pit Mode                      : " << p->pit_mode()                      << endl;
            cout << "Pit Schedule                  : " << p->pit_schedule()                  << endl;
            cout << "Oil Temp Celsius              : " << p->oil_temp_celsius()              << endl;
            cout << "Oil Pressure KPA              : " << p->oil_pressure_kpa()              << endl;
            cout << "Water Temp Celsius            : " << p->water_temp_celsius()            << endl;
            cout << "Water Pressure KPA            : " << p->water_pressure_kpa()            << endl;
            cout << "Fuel Pressure KPA             : " << p->fuel_pressure_kpa()             << endl;
            cout << "Car Flags                     : " << p->car_flags()                     << endl;
            cout << "Fuel Capacity                 : " << p->fuel_capacity()                 << endl;
            cout << "Brake                         : " << p->brake()                         << endl;
            cout << "Throttle                      : " << p->throttle()                      << endl;
            cout << "Clutch                        : " << p->clutch()                        << endl;
            cout << "Steering                      : " << p->steering()                      << endl;
            cout << "Fuel Level                    : " << p->fuel_level()                    << endl;
            cout << "Speed                         : " << p->speed()                         << endl;
            cout << "RPM                           : " << p->rpm()                           << endl;
            cout << "Max RPM                       : " << p->max_rpm()                       << endl;
            cout << "Number of Gears               : " << p->num_gears()                     << endl;
            cout << "Gear                          : " << p->gear()                          << endl;
            cout << "Boost Amount                  : " << p->boost_amount()                  << endl;
            cout << "Enforced Pit Stop Lap         : " << p->enforced_pit_stop_lap()         << endl;
            cout << "Crash State                   : " << p->crash_state()                   << endl;
            cout << "Odometer KM                   : " << p->odometer_km()                   << endl;
            cout << "Orientation 1                 : " << p->orientation().at(0)             << endl;
            cout << "Orientation 2                 : " << p->orientation().at(1)             << endl;
            cout << "Orientation 3                 : " << p->orientation().at(2)             << endl;
            cout << "Local Velocity 1              : " << p->local_velocity().at(0)          << endl;
            cout << "Local Velocity 2              : " << p->local_velocity().at(1)          << endl;
            cout << "Local Velocity 3              : " << p->local_velocity().at(2)          << endl;
            cout << "World Velocity 1              : " << p->world_velocity().at(0)          << endl;
            cout << "World Velocity 2              : " << p->world_velocity().at(1)          << endl;
            cout << "World Velocity 3              : " << p->world_velocity().at(2)          << endl;
            cout << "Angular Velocity 1            : " << p->angular_velocity().at(0)        << endl;
            cout << "Angular Velocity 2            : " << p->angular_velocity().at(1)        << endl;
            cout << "Angular Velocity 3            : " << p->angular_velocity().at(2)        << endl;	
            cout << "Local Acceleration 1          : " << p->local_acceleration().at(0)      << endl;
            cout << "Local Acceleration 2          : " << p->local_acceleration().at(1)      << endl;    
            cout << "Local Acceleration 3          : " << p->local_acceleration().at(2)      << endl;    
            cout << "World Acceleration 1          : " << p->world_acceleration().at(0)      << endl;
            cout << "World Acceleration 2          : " << p->world_acceleration().at(1)      << endl;    
            cout << "World Acceleration 3          : " << p->world_acceleration().at(2)      << endl; 
            cout << "Extents Centre 1              : " << p->extents_centre().at(0)          << endl;
            cout << "Extents Centre 2              : " << p->extents_centre().at(1)          << endl;    
            cout << "Extents Centre 3              : " << p->extents_centre().at(2)          << endl; 
            cout << "Tyre Flags 1                  : " << p->tyre_flags().at(0)              << endl;
            cout << "Tyre Flags 2                  : " << p->tyre_flags().at(1)              << endl;
            cout << "Tyre Flags 3                  : " << p->tyre_flags().at(2)              << endl;
            cout << "Tyre Flags 4                  : " << p->tyre_flags().at(3)              << endl;
            cout << "Terrain 1                     : " << p->terrain().at(0)                 << endl;
            cout << "Terrain 2                     : " << p->terrain().at(1)                 << endl;
            cout << "Terrain 3                     : " << p->terrain().at(2)                 << endl;
            cout << "Terrain 4                     : " << p->terrain().at(3)                 << endl;
            cout << "Tyre Y 1                      : " << p->tyre_y().at(0)                  << endl;
            cout << "Tyre Y 2                      : " << p->tyre_y().at(1)                  << endl;
            cout << "Tyre Y 3                      : " << p->tyre_y().at(2)                  << endl;
            cout << "Tyre Y 4                      : " << p->tyre_y().at(3)                  << endl;
            cout << "Tyre RPS 1                    : " << p->tyre_rps().at(0)                << endl;
            cout << "Tyre RPS 2                    : " << p->tyre_rps().at(1)                << endl;
            cout << "Tyre RPS 3                    : " << p->tyre_rps().at(2)                << endl;
            cout << "Tyre RPS 4                    : " << p->tyre_rps().at(3)                << endl;
            cout << "Tyre Slip Speed 1             : " << p->tyre_slip_speed().at(0)         << endl;
            cout << "Tyre Slip Speed 2             : " << p->tyre_slip_speed().at(1)         << endl;
            cout << "Tyre Slip Speed 3             : " << p->tyre_slip_speed().at(2)         << endl;
            cout << "Tyre Slip Speed 4             : " << p->tyre_slip_speed().at(3)         << endl;
            cout << "Tyre Temp 1                   : " << p->tyre_temp().at(0)               << endl;
            cout << "Tyre Temp 2                   : " << p->tyre_temp().at(1)               << endl;
            cout << "Tyre Temp 3                   : " << p->tyre_temp().at(2)               << endl;
            cout << "Tyre Temp 4                   : " << p->tyre_temp().at(3)               << endl;
            cout << "Tyre Grip 1                   : " << p->tyre_grip().at(0)               << endl;
            cout << "Tyre Grip 2                   : " << p->tyre_grip().at(1)               << endl;
            cout << "Tyre Grip 3                   : " << p->tyre_grip().at(2)               << endl;
            cout << "Tyre Grip 4                   : " << p->tyre_grip().at(3)               << endl;
            cout << "Tyre Height Above Ground 1    : " << p->tyre_height_above_ground().at(0)<< endl;
            cout << "Tyre Height Above Ground 2    : " << p->tyre_height_above_ground().at(1)<< endl;
            cout << "Tyre Height Above Ground 3    : " << p->tyre_height_above_ground().at(2)<< endl;
            cout << "Tyre Height Above Ground 4    : " << p->tyre_height_above_ground().at(3)<< endl;
            cout << "Tyre Lateral Stiffness 1      : " << p->tyre_lateral_stiffness().at(0)  << endl;
            cout << "Tyre Lateral Stiffness 2      : " << p->tyre_lateral_stiffness().at(1)  << endl;
            cout << "Tyre Lateral Stiffness 3      : " << p->tyre_lateral_stiffness().at(2)  << endl;
            cout << "Tyre Lateral Stiffness 4      : " << p->tyre_lateral_stiffness().at(3)  << endl;
            cout << "Tyre Wear 1                   : " << p->tyre_wear().at(0)               << endl;
            cout << "Tyre Wear 2                   : " << p->tyre_wear().at(1)               << endl;
            cout << "Tyre Wear 3                   : " << p->tyre_wear().at(2)               << endl;
            cout << "Tyre Wear 4                   : " << p->tyre_wear().at(3)               << endl;
            cout << "Brake Damage 1                : " << p->brake_damage().at(0)            << endl;
            cout << "Brake Damage 2                : " << p->brake_damage().at(1)            << endl;
            cout << "Brake Damage 3                : " << p->brake_damage().at(2)            << endl;
            cout << "Brake Damage 4                : " << p->brake_damage().at(3)            << endl;
            cout << "Suspension Damage 1           : " << p->suspension_damage().at(0)       << endl;
            cout << "Suspension Damage 2           : " << p->suspension_damage().at(1)       << endl;
            cout << "Suspension Damage 3           : " << p->suspension_damage().at(2)       << endl;
            cout << "Suspension Damage 4           : " << p->suspension_damage().at(3)       << endl;
            cout << "Brake Temp Celsius 1          : " << p->brake_temp_celsius().at(0)      << endl;
            cout << "Brake Temp Celsius 2          : " << p->brake_temp_celsius().at(1)      << endl;
            cout << "Brake Temp Celsius 3          : " << p->brake_temp_celsius().at(2)      << endl;
            cout << "Brake Temp Celsius 4          : " << p->brake_temp_celsius().at(3)      << endl;
            cout << "Tyre Tread Temp 1             : " << p->tyre_tread_temp().at(0)         << endl;
            cout << "Tyre Tread Temp 2             : " << p->tyre_tread_temp().at(1)         << endl;
            cout << "Tyre Tread Temp 3             : " << p->tyre_tread_temp().at(2)         << endl;
            cout << "Tyre Tread Temp 4             : " << p->tyre_tread_temp().at(3)         << endl;
            cout << "Tyre Layer Temp 1             : " << p->tyre_layer_temp().at(0)         << endl;
            cout << "Tyre Layer Temp 2             : " << p->tyre_layer_temp().at(1)         << endl;
            cout << "Tyre Layer Temp 3             : " << p->tyre_layer_temp().at(2)         << endl;
            cout << "Tyre Layer Temp 4             : " << p->tyre_layer_temp().at(3)         << endl;
            cout << "Tyre Carcass Temp 1           : " << p->tyre_carcass_temp().at(0)       << endl;
            cout << "Tyre Carcass Temp 2           : " << p->tyre_carcass_temp().at(1)       << endl;
            cout << "Tyre Carcass Temp 3           : " << p->tyre_carcass_temp().at(2)       << endl;
            cout << "Tyre Carcass Temp 4           : " << p->tyre_carcass_temp().at(3)       << endl;
            cout << "Tyre Rim Temp 1               : " << p->tyre_rim_temp().at(0)           << endl;
            cout << "Tyre Rim Temp 2               : " << p->tyre_rim_temp().at(1)           << endl;
            cout << "Tyre Rim Temp 3               : " << p->tyre_rim_temp().at(2)           << endl;
            cout << "Tyre Rim Temp 4               : " << p->tyre_rim_temp().at(3)           << endl;
            cout << "Tyre Internal Air Temp 1      : " << p->tyre_internal_air_temp().at(0)  << endl;
            cout << "Tyre Internal Air Temp 2      : " << p->tyre_internal_air_temp().at(1)  << endl;
            cout << "Tyre Internal Air Temp 3      : " << p->tyre_internal_air_temp().at(2)  << endl;
            cout << "Tyre Internal Air Temp 4      : " << p->tyre_internal_air_temp().at(3)  << endl;
            cout << "Wheel Local Position Y 1      : " << p->wheel_local_position_y().at(0)  << endl;
            cout << "Wheel Local Position Y 2      : " << p->wheel_local_position_y().at(1)  << endl;
            cout << "Wheel Local Position Y 3      : " << p->wheel_local_position_y().at(2)  << endl;
            cout << "Wheel Local Position Y 4      : " << p->wheel_local_position_y().at(3)  << endl;
            cout << "Ride Height 1                 : " << p->ride_height().at(0)             << endl;
            cout << "Ride Height 2                 : " << p->ride_height().at(1)             << endl;
            cout << "Ride Height 3                 : " << p->ride_height().at(2)             << endl;
            cout << "Ride Height 4                 : " << p->ride_height().at(3)             << endl;
            cout << "Suspension Travel 1           : " << p->suspension_travel().at(0)       << endl;
            cout << "Suspension Travel 2           : " << p->suspension_travel().at(1)       << endl;
            cout << "Suspension Travel 3           : " << p->suspension_travel().at(2)       << endl;
            cout << "Suspension Travel 4           : " << p->suspension_travel().at(3)       << endl;
            cout << "Suspension Velocity 1         : " << p->suspension_velocity().at(0)     << endl;
            cout << "Suspension Velocity 2         : " << p->suspension_velocity().at(1)     << endl;
            cout << "Suspension Velocity 3         : " << p->suspension_velocity().at(2)     << endl;
            cout << "Suspension Velocity 4         : " << p->suspension_velocity().at(3)     << endl;
            cout << "Air Pressure 1                : " << p->air_pressure().at(0)            << endl;
            cout << "Air Pressure 2                : " << p->air_pressure().at(1)            << endl;
            cout << "Air Pressure 3                : " << p->air_pressure().at(2)            << endl;
            cout << "Air Pressure 4                : " << p->air_pressure().at(3)            << endl;
            cout << "Engine Speed                  : " << p->engine_speed()                  << endl;
            cout << "Engine Torque                 : " << p->engine_torque()                 << endl;
            cout << "Aero Damage                   : " << p->aero_damage()                   << endl;
            cout << "Engine Damage                 : " << p->engine_damage()                 << endl;
            cout << "Ambient Temperature           : " << p->ambient_temperature()           << endl;
            cout << "Track Temperature             : " << p->track_temperature()             << endl;
            cout << "Rain Density                  : " << p->rain_density()                  << endl;
            cout << "Wind Speed                    : " << p->wind_speed()                    << endl;
            cout << "Wind Direction X              : " << p->wind_direction_x()              << endl;
            cout << "Wind Direction Y              : " << p->wind_direction_y()              << endl;
            cout << "Track Length                  : " << p->track_length()                  << endl;
            cout << "Wings 1                       : " << p->wings().at(0)                   << endl;
            cout << "Wings 2                       : " << p->wings().at(1)                   << endl;
            cout << "DPad                          : " << p->dpad()                          << endl;

            for (int i = 0; i < p->num_participants(); ++i) {
                cout << endl << "Participant " << (i + 1) << endl << endl;
                cout << "   World Position 1           : " << p->participant_info().at(i).world_position().at(0) << endl;
                cout << "   World Position 2           : " << p->participant_info().at(i).world_position().at(1) << endl;
                cout << "   World Position 3           : " << p->participant_info().at(i).world_position().at(2) << endl;
                cout << "   Current Lap Distance       : " << p->participant_info().at(i).current_lap_distance() << endl;
                cout << "   Is Active                  : " << p->participant_info().at(i).is_active()            << endl;
                cout << "   Race Postion               : " << p->participant_info().at(i).race_position()        << endl;
                cout << "   Lap Invalid                : " << p->participant_info().at(i).lap_invalidated()      << endl;
                cout << "   Laps Completed             : " << p->participant_info().at(i).laps_completed()       << endl;
                cout << "   Same Class                 : " << p->participant_info().at(i).same_class()           << endl;
                cout << "   World Position Z           : " << p->participant_info().at(i).world_positionZ()      << endl;
                cout << "   World Position X           : " << p->participant_info().at(i).world_positionX()      << endl;
                cout << "   Sector                     : " << p->participant_info().at(i).sector()               << endl;
                cout << "   Last Sector Time           : " << p->participant_info().at(i).last_sector_time()     << endl;
            }
        

        }

        if (packet->type() == PACKETTYPE::PACKETPARTICIPANTINFOSTRINGS) {
            PacketParticipantInfoStrings * p = dynamic_cast<PacketParticipantInfoStrings *>(packet.get());
            cout << endl << "Participant Info Strings " << endl << endl;
 
            cout << "Build Version             : " << p->build_version()   << endl;
            cout << "Sequence Number           : " << p->sequence_number() << endl;
            cout << "Packet Type               : " << p->packet_type()     << endl;
            cout << "Car Name                  : " << p->car_name()        << endl;
            cout << "Car Class Name            : " << p->car_class_name()  << endl;
            cout << "Track Location            : " << p->track_location()  << endl;
            cout << "Track Variation           : " << p->track_variation() << endl;

            for (int i = 0 ; i < participants_ && i < 16; ++i) {
                cout << "Name " << i << " : " << p->names().at(i) << " " <<
                        "Fastest Time : " << p->fastest_lap_times().at(i) << endl;
            }
        }

        if (packet->type() == PACKETTYPE::PACKETPARTICIPANTINFOSTRINGSADDITIONAL) {
            PacketParticipantInfoStringsAdditional * p = dynamic_cast<PacketParticipantInfoStringsAdditional *>(packet.get());
            cout << endl << "Participant Info Strings Additional" << endl << endl;
 
            cout << "Build Version             : " << p->build_version()   << endl;
            cout << "Sequence Number           : " << p->sequence_number() << endl;
            cout << "Packet Type               : " << p->packet_type()     << endl;
            cout << "Offset                    : " << p->offset()          << endl;

            for (size_t i = 0 ; i < p->names().size(); ++i) {
                cout << "Name " << i << " : " << p->names().at(i) << endl;
            }
        }
    }

    void MyProcessV2::playing(Packet::Ptr & packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA) {
            PacketTelemetryData * p = dynamic_cast<PacketTelemetryData *>(packet.get());

            cout << endl << "Packet Telemetry Data" << endl << endl;
            cout << "Viewed Participant Index : " << p->viewed_participant_index()      << endl;
            cout << "Unfiltered Throttle      : " << p->unfiltered_throttle()           << endl;
            cout << "Unfiltered Brake         : " << p->unfiltered_brake()              << endl;
            cout << "Unfiltered Steering      : " << p->unfiltered_steering()           << endl;
            cout << "Unfiltered Clutch        : " << p->unfiltered_clutch()             << endl;
            cout << "Car Flags                : " << p->car_flags()                     << endl;
            cout << "Oil Temp Celsius         : " << p->oil_temp_celsius()              << endl;
            cout << "Oil Pressure KPA         : " << p->oil_pressure_kpa()              << endl;
            cout << "Water Temp Celsius       : " << p->water_temp_celsius()            << endl;
            cout << "Water Pressure KPA       : " << p->water_pressure_kpa()            << endl;
            cout << "Fuel Pressure KPA        : " << p->fuel_pressure_kpa()             << endl;
            cout << "Fuel Capacity            : " << p->fuel_capacity()                 << endl;
            cout << "Brake                    : " << p->brake()                         << endl;
            cout << "Throttle                 : " << p->throttle()                      << endl;
            cout << "Clutch                   : " << p->clutch()                        << endl;
            cout << "Fuel Level               : " << p->fuel_level()                    << endl;
            cout << "Speed                    : " << p->speed()                         << endl;
            cout << "RPM                      : " << p->rpm()                           << endl;
            cout << "Max RPM                  : " << p->max_rpm()                       << endl;
            cout << "Steering                 : " << p->steering()                      << endl;
            cout << "Gears                    : " << p->gears()                         << endl;
            cout << "Gear                     : " << p->gear()                          << endl;
            cout << "Boost Amount             : " << p->boost_amount()                  << endl;
            cout << "Crash State              : " << p->crash_state()                   << endl;
            cout << "Odometer KM              : " << p->odometer_km()                   << endl;
            cout << "Orientation 1            : " << p->orientation().at(0)             << endl;
            cout << "Orientation 2            : " << p->orientation().at(1)             << endl;
            cout << "Orientation 3            : " << p->orientation().at(2)             << endl;
            cout << "Local Velocity 1         : " << p->local_velocity().at(0)          << endl;
            cout << "Local Velocity 2         : " << p->local_velocity().at(1)          << endl;
            cout << "Local Velocity 3         : " << p->local_velocity().at(2)          << endl;
            cout << "World Velocity 1         : " << p->world_velocity().at(0)          << endl;
            cout << "World Velocity 2         : " << p->world_velocity().at(1)          << endl;
            cout << "World Velocity 3         : " << p->world_velocity().at(2)          << endl;
            cout << "Angular Velocity 1       : " << p->angular_velocity().at(0)        << endl;
            cout << "Angular Velocity 2       : " << p->angular_velocity().at(1)        << endl;
            cout << "Angular Velocity 3       : " << p->angular_velocity().at(2)        << endl;
            cout << "Local Acceleration 1     : " << p->local_acceleration().at(0)      << endl;
            cout << "Local Acceleration 2     : " << p->local_acceleration().at(1)      << endl;
            cout << "Local Acceleration 3     : " << p->local_acceleration().at(2)      << endl;
            cout << "World Acceleration 1     : " << p->world_acceleration().at(0)      << endl;
            cout << "World Acceleration 2     : " << p->world_acceleration().at(1)      << endl;
            cout << "World Acceleration 3     : " << p->world_acceleration().at(2)      << endl;
            cout << "Extends Centre 1         : " << p->extents_centre().at(0)          << endl;
            cout << "Extends Centre 2         : " << p->extents_centre().at(1)          << endl;
            cout << "Extends Centre 3         : " << p->extents_centre().at(2)          << endl;
            cout << "Tyre Flags 1             : " << p->tyre_flags().at(0)              << endl;
            cout << "Tyre Flags 2             : " << p->tyre_flags().at(1)              << endl;
            cout << "Tyre Flags 3             : " << p->tyre_flags().at(2)              << endl;
            cout << "Tyre Flags 4             : " << p->tyre_flags().at(3)              << endl;
            cout << "Terrain 1                : " << p->terrain().at(0)                 << endl;
            cout << "Terrain 2                : " << p->terrain().at(1)                 << endl;
            cout << "Terrain 3                : " << p->terrain().at(2)                 << endl;
            cout << "Terrain 4                : " << p->terrain().at(3)                 << endl;
            cout << "Tyre Y 1                 : " << p->tyre_y().at(0)                  << endl;
            cout << "Tyre Y 2                 : " << p->tyre_y().at(1)                  << endl;
            cout << "Tyre Y 3                 : " << p->tyre_y().at(2)                  << endl;
            cout << "Tyre Y 4                 : " << p->tyre_y().at(3)                  << endl;
            cout << "Tyre RPS 1               : " << p->tyre_rps().at(0)                << endl;
            cout << "Tyre RPS 2               : " << p->tyre_rps().at(1)                << endl;
            cout << "Tyre RPS 3               : " << p->tyre_rps().at(2)                << endl;
            cout << "Tyre RPS 4               : " << p->tyre_rps().at(3)                << endl;
            cout << "Tyre Temp 1              : " << p->tyre_temp().at(0)               << endl;
            cout << "Tyre Temp 2              : " << p->tyre_temp().at(1)               << endl;
            cout << "Tyre Temp 3              : " << p->tyre_temp().at(2)               << endl;
            cout << "Tyre Temp 4              : " << p->tyre_temp().at(3)               << endl;
            cout << "Tyre Height Above Ground 1 : " << p->tyre_height_above_ground().at(0) << endl;
            cout << "Tyre Height Above Ground 2 : " << p->tyre_height_above_ground().at(1) << endl; 
            cout << "Tyre Height Above Ground 3 : " << p->tyre_height_above_ground().at(2) << endl; 
            cout << "Tyre Height Above Ground 4 : " << p->tyre_height_above_ground().at(3) << endl; 
            cout << "Tyre Wear 1              : " << p->tyre_wear().at(0)               << endl;
            cout << "Tyre Wear 2              : " << p->tyre_wear().at(1)               << endl;
            cout << "Tyre Wear 3              : " << p->tyre_wear().at(2)               << endl;
            cout << "Tyre Wear 4              : " << p->tyre_wear().at(3)               << endl;
            cout << "Brake Damage 1           : " << p->brake_damage().at(0)            << endl;
            cout << "Brake Damage 2           : " << p->brake_damage().at(1)            << endl;
            cout << "Brake Damage 3           : " << p->brake_damage().at(2)            << endl;
            cout << "Brake Damage 4           : " << p->brake_damage().at(3)            << endl;
            cout << "Suspension Damage 1      : " << p->suspension_damage().at(0)       << endl;
            cout << "Suspension Damage 2      : " << p->suspension_damage().at(1)       << endl;
            cout << "Suspension Damage 3      : " << p->suspension_damage().at(2)       << endl;
            cout << "Suspension Damage 4      : " << p->suspension_damage().at(3)       << endl;
            cout << "Brake Temp Celsuis 1     : " << p->brake_temp_celsius().at(0)      << endl;
            cout << "Brake Temp Celsuis 2     : " << p->brake_temp_celsius().at(1)      << endl;
            cout << "Brake Temp Celsuis 3     : " << p->brake_temp_celsius().at(2)      << endl;
            cout << "Brake Temp Celsuis 4     : " << p->brake_temp_celsius().at(3)      << endl;
            cout << "Tyre Tread Temp 1        : " << p->tyre_tread_temp().at(0)         << endl;
            cout << "Tyre Tread Temp 2        : " << p->tyre_tread_temp().at(1)         << endl;
            cout << "Tyre Tread Temp 3        : " << p->tyre_tread_temp().at(2)         << endl;
            cout << "Tyre Tread Temp 4        : " << p->tyre_tread_temp().at(3)         << endl;
            cout << "Tyre Layer Temp 1        : " << p->tyre_layer_temp().at(0)         << endl;
            cout << "Tyre Layer Temp 2        : " << p->tyre_layer_temp().at(1)         << endl;
            cout << "Tyre Layer Temp 3        : " << p->tyre_layer_temp().at(2)         << endl;
            cout << "Tyre Layer Temp 4        : " << p->tyre_layer_temp().at(3)         << endl;
            cout << "Tyre Carcass Temp 1      : " << p->tyre_carcass_temp().at(0)       << endl;
            cout << "Tyre Carcass Temp 2      : " << p->tyre_carcass_temp().at(1)       << endl;
            cout << "Tyre Carcass Temp 3      : " << p->tyre_carcass_temp().at(2)       << endl;
            cout << "Tyre Carcass Temp 4      : " << p->tyre_carcass_temp().at(3)       << endl;
            cout << "Tyre Rim Temp 1          : " << p->tyre_rim_temp().at(0)           << endl;
            cout << "Tyre Rim Temp 2          : " << p->tyre_rim_temp().at(1)           << endl;
            cout << "Tyre Rim Temp 3          : " << p->tyre_rim_temp().at(2)           << endl;
            cout << "Tyre Rim Temp 4          : " << p->tyre_rim_temp().at(3)           << endl;
            cout << "Tyre Internal Air Temp 1 : " << p->tyre_internal_air_temp().at(0)  << endl;
            cout << "Tyre Internal Air Temp 2 : " << p->tyre_internal_air_temp().at(1)  << endl;
            cout << "Tyre Internal Air Temp 3 : " << p->tyre_internal_air_temp().at(2)  << endl;
            cout << "Tyre Internal Air Temp 4 : " << p->tyre_internal_air_temp().at(3)  << endl;
            cout << "Tyre Temp Left 1         : " << p->tyre_temp_left().at(0)          << endl;
            cout << "Tyre Temp Left 2         : " << p->tyre_temp_left().at(1)          << endl;
            cout << "Tyre Temp Left 3         : " << p->tyre_temp_left().at(2)          << endl;
            cout << "Tyre Temp Left 4         : " << p->tyre_temp_left().at(3)          << endl;
            cout << "Tyre Temp center 1       : " << p->tyre_temp_center().at(0)        << endl;
            cout << "Tyre Temp center 2       : " << p->tyre_temp_center().at(1)        << endl;
            cout << "Tyre Temp center 3       : " << p->tyre_temp_center().at(2)        << endl;
            cout << "Tyre Temp center 4       : " << p->tyre_temp_center().at(3)        << endl;
            cout << "Tyre Temp Right 1        : " << p->tyre_temp_right().at(0)         << endl;
            cout << "Tyre Temp Right 2        : " << p->tyre_temp_right().at(1)         << endl;
            cout << "Tyre Temp Right 3        : " << p->tyre_temp_right().at(2)         << endl;
            cout << "Tyre Temp Right 4        : " << p->tyre_temp_right().at(3)         << endl;
            cout << "Wheel Local Position y 1 : " << p->wheel_local_position_y().at(0)  << endl;
            cout << "Wheel Local Position y 2 : " << p->wheel_local_position_y().at(1)  << endl;
            cout << "Wheel Local Position y 3 : " << p->wheel_local_position_y().at(2)  << endl;
            cout << "Wheel Local Position y 4 : " << p->wheel_local_position_y().at(3)  << endl;
            cout << "Ride Height 1            : " << p->ride_height().at(0)             << endl;
            cout << "Ride Height 2            : " << p->ride_height().at(1)             << endl;
            cout << "Ride Height 3            : " << p->ride_height().at(2)             << endl;
            cout << "Ride Height 4            : " << p->ride_height().at(3)             << endl;
            cout << "Suspension Travel 1      : " << p->suspension_travel().at(0)       << endl;
            cout << "Suspension Travel 2      : " << p->suspension_travel().at(1)       << endl;
            cout << "Suspension Travel 3      : " << p->suspension_travel().at(2)       << endl;
            cout << "Suspension Travel 4      : " << p->suspension_travel().at(3)       << endl;
            cout << "Suspension Velocity 1    : " << p->suspension_velocity().at(0)     << endl;
            cout << "Suspension Velocity 2    : " << p->suspension_velocity().at(1)     << endl;
            cout << "Suspension Velocity 3    : " << p->suspension_velocity().at(2)     << endl;
            cout << "Suspension Velocity 4    : " << p->suspension_velocity().at(3)     << endl;
            cout << "Suspension Ride Height 1 : " << p->suspension_ride_height().at(0)  << endl;
            cout << "Suspension Ride Height 2 : " << p->suspension_ride_height().at(1)  << endl;
            cout << "Suspension Ride Height 3 : " << p->suspension_ride_height().at(2)  << endl;
            cout << "Suspension Ride Height 4 : " << p->suspension_ride_height().at(3)  << endl;
            cout << "Air Pressure 1           : " << p->air_pressure().at(0)            << endl;
            cout << "Air Pressure 2           : " << p->air_pressure().at(1)            << endl;
            cout << "Air Pressure 3           : " << p->air_pressure().at(2)            << endl;
            cout << "Air Pressure 4           : " << p->air_pressure().at(3)            << endl;
            cout << "Engine Speed             : " << p->engine_speed()                  << endl;
            cout << "Engine Torque            : " << p->engine_torque()                 << endl;
            cout << "Wings 1                  : " << p->wings().at(0)                   << endl;
            cout << "Wings 2                  : " << p->wings().at(1)                   << endl;
            cout << "Handbrake                : " << p->handbrake()                     << endl;
            cout << "Aero Damage              : " << p->aero_damage()                   << endl;
            cout << "Engine Damage            : " << p->engine_damage()                 << endl;
            cout << "Joy Pad                  : " << p->joy_pad_0()                     << endl;
            cout << "D Pad                    : " << p->d_pad()                         << endl;
            cout << "Tyre Compound 1          : " << p->tyre_compound().at(0)           << endl;
            cout << "Tyre Compound 2          : " << p->tyre_compound().at(1)           << endl;
            cout << "Tyre Compound 3          : " << p->tyre_compound().at(2)           << endl;
            cout << "Tyre Compound 4          : " << p->tyre_compound().at(3)           << endl;
            cout << "Turbo Boost Pressure 1   : " << p->turbo_boost_pressure()          << endl;
            cout << "Full Position 1          : " << p->full_position().at(0)           << endl;
            cout << "Full Position 2          : " << p->full_position().at(1)           << endl;
            cout << "Full Position 3          : " << p->full_position().at(2)           << endl;
            cout << "Brake Bias               : " << p->brake_bias()                    << endl;
            cout << "Tick Count               : " << p->tick_count()                    << endl;
        
        }
        if (packet->type() == PACKETTYPE::PACKETRACEDATA) {
            PacketRaceData * p = dynamic_cast<PacketRaceData *>(packet.get());
 
            cout << endl << "Packet Race Data" << endl << endl;
            cout << "World Fastest Lap Time          : " << p->world_fastest_lap_time()        << endl;
            cout << "Personal Fastest Lap Time       : " << p->personal_fastest_lap_time()     << endl; 
            cout << "Personal Fastest Sector 1 Time  : " << p->personal_fastest_sector1_time() << endl;
            cout << "Personal Fastest Sector 2 Time  : " << p->personal_fastest_sector2_time() << endl;
            cout << "Personal Fastest Sector 3 Time  : " << p->personal_fastest_sector3_time() << endl;
            cout << "World Fastest Sector 1 Time     : " << p->world_fastest_sector1_time()    << endl;
            cout << "World Fastest Sector 2 Time     : " << p->world_fastest_sector2_time()    << endl;
            cout << "World Fastest Sector 3 Time     : " << p->world_fastest_sector3_time()    << endl;
            cout << "Track Length                    : " << p->track_length()                  << endl;
            cout << "Track Location                  : " << p->track_location()                << endl;
            cout << "Track Variation                 : " << p->track_variation()               << endl;
            cout << "Translated Track Location       : " << p->translated_track_location()     << endl;
            cout << "Translated Track Variation      : " << p->translated_track_variation()    << endl;
            cout << "Laps Time in Event              : " << p->laps_time_in_event()            << endl;
            cout << "Enforced Pit Stop Lap           : " << p->enforced_pitstop_lap()          << endl; 
        }
        if (packet->type() == PACKETTYPE::PACKETPARTICIPANTSDATA) {
            PacketParticipantsData * p = dynamic_cast<PacketParticipantsData *>(packet.get());

            cout << endl << "Packet Participants Data" << endl << endl;

            cout << "Participants Changed Timestamp      : " << p->participants_changed_timestamp() << endl;
            
            for (size_t i = 0; i < p->name().size(); ++i) {
                cout << "Name " << " " << i << " " << p->name().at(i) << endl;
                cout << "   Nationality : " << p->nationality().at(i) << endl;
                cout << "   Index       : " << p->index().at(i)       << endl; 
            }

        }

        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA) {
            PacketTimingData * p = dynamic_cast<PacketTimingData *>(packet.get());

            cout << endl << "Packet Timing Data" << endl << endl;

            cout << "Number Participants                 : " << p->num_participants()               << endl;
            cout << "Participants Changed Timestamp      : " << p->participants_changed_timestamp() << endl;
            cout << "Event Time Remaining                : " << p->event_time_remaining()           << endl;
            cout << "Split Time Ahead                    : " << p->split_time_ahead()               << endl;
            cout << "Split Time Behind                   : " << p->split_time_behind()              << endl;
            cout << "Split Time                          : " << p->split_time()                     << endl;
            cout << "Local Participant Index             : " << p->local_participant_index()        << endl;
            cout << "Tick Count                          : " << p->tick_count()                     << endl;

            for (size_t i = 0; i < p->partcipants().size(); ++i) {
                cout << "World Position x " << i << " " << p->partcipants().at(i).world_position().at(0) << endl;
                cout << "World Position y " << i << " " << p->partcipants().at(i).world_position().at(1) << endl;
                cout << "World Position z " << i << " " << p->partcipants().at(i).world_position().at(2) << endl;            
                cout << "Orientation x " << i << " " << p->partcipants().at(i).orientation().at(0) << endl;
                cout << "Orientation y " << i << " " << p->partcipants().at(i).orientation().at(1) << endl;
                cout << "Orientation z " << i << " " << p->partcipants().at(i).orientation().at(2) << endl;
                cout << "Current Lap Distance " << i << " " << p->partcipants().at(i).current_lap_distance() << endl;
                cout << "Race Position " << i << " " << p->partcipants().at(i).race_position() << endl;
                cout << "Is Acitve " << i << " " << p->partcipants().at(i).is_active() << endl;
                cout << "ZX Position " << i << " " << p->partcipants().at(i).zx_position() << endl;
                cout << "Sector " << i << " " << p->partcipants().at(i).sector() << endl;
                cout << "Flag Colour " << i << " " << p->partcipants().at(i).flag_colour() << endl;
                cout << "Flag Reason " << i << " " << p->partcipants().at(i).flag_reason() << endl;
                cout << "Pit Mode " << i << " " << p->partcipants().at(i).pit_mode() << endl;
                cout << "Pit Mode Schedule " << i << " " << p->partcipants().at(i).pit_mode_schedule() << endl;
                cout << "Car Index " << i << " " << p->partcipants().at(i).car_index() << endl;
                cout << "Local Player " << i << " " << p->partcipants().at(i).local_player() << endl;
                cout << "Remote Player " << i << " " << p->partcipants().at(i).remote_player() << endl;
                cout << "Human Player " << i << " " << p->partcipants().at(i).human_player() << endl;
                cout << "Non Human Player " << i << " " << p->partcipants().at(i).none_human_player() << endl;
                cout << "Race State " << i << " " << p->partcipants().at(i).race_state() << endl;
                cout << "Invalid Lap " << i << " " << p->partcipants().at(i).invalid_lap() << endl;
                cout << "Current Lap " << i << " " << p->partcipants().at(i).current_lap() << endl;
                cout << "Current Time " << i << " " << p->partcipants().at(i).current_time() << endl;
                cout << "Current Sector Time " << i << " " << p->partcipants().at(i).current_sector_time() << endl;
                cout << "MP Participant Index " << i << " " << p->partcipants().at(i).mp_participant_index() << endl;
            }
        }


        if (packet->type() == PACKETTYPE::PACKETGAMESTATE) {
            PacketGameState * p = dynamic_cast<PacketGameState *>(packet.get());

            cout << endl << "Packet Game State" << endl << endl;

            cout << "Build Version             : " << p->build_version()       << endl;
            cout << "Game State                : " << p->game_state()          << endl;
            cout << "Session State             : " << p->sessin_state()        << endl;
            cout << "Ambient Temp              : " << p->ambient_temperature() << endl; 
            cout << "Track Temp                : " << p->track_temperature()   << endl;
            cout << "Rain Density              : " << p->rain_density()        << endl;
            cout << "Snow Density              : " << p->snow_density()        << endl;
            cout << "Wind Speed                : " << p->wind_speed()          << endl;
            cout << "Wind Direction X          : " << p->wind_direction_x()    << endl;
            cout << "Wind Direction Y          : " << p->wind_direction_y()    << endl;
        }

        if (packet->type() == PACKETTYPE::PACKETTIMESTATSDATA) {
            PacketTimeStatsData * p = dynamic_cast<PacketTimeStatsData *>(packet.get());

            cout << endl << "Packet Time Stats Data" << endl << endl;

            cout << "Participants Changed Timestamp   : " << p->participants_changed_timestamp() << endl;

            for (size_t i = 0; i < p->stats().size(); ++i) {
                cout << "Fastest Lap Time       " << i << " " << p->stats().at(i).fastest_lap_time() << endl;
                cout << "Last Lap Time          " << i << " " << p->stats().at(i).last_lap_time() << endl;
                cout << "Last Sector Time       " << i << " " << p->stats().at(i).last_sector_time() << endl;
                cout << "Fastest Sector 1 Time  " << i << " " << p->stats().at(i).fastest_sector1_time() << endl;
                cout << "Fastest Sector 2 Time  " << i << " " << p->stats().at(i).fastest_sector2_time() << endl;
                cout << "Fastest Sector 3 Time  " << i << " " << p->stats().at(i).fastest_sector3_time() << endl;
                cout << "Participant Online Rep " << i << " " << p->stats().at(i).participant_online_rep() << endl;
                cout << "MP Participant Index   " << i << " " << p->stats().at(i).mp_participant_index() << endl;
            }
        }

        if (packet->type() == PACKETTYPE::PACKETPARTICIPANTSVEHICLENAMESDATA) {
            PacketParticipantsVehicleNamesData * p = dynamic_cast<PacketParticipantsVehicleNamesData *>(packet.get());

            cout << endl << "Packet Participants Vehicle Names Data" << endl << endl;

            for (size_t i = 0; i < p->vehicle_info().size(); ++i) {
                cout << "Index      " << i << " " << p->vehicle_info().at(i).index() << endl;
                cout << "Class Name " << i << " " << p->vehicle_info().at(i).class_name() << endl;
                cout << "Name       " << i << " " << p->vehicle_info().at(i).name() << endl;
            }
        }

        if (packet->type() == PACKETTYPE::PACKETVEHICLECLASSNAMESDATA) {
            PacketVehicleClassNamesData * p = dynamic_cast<PacketVehicleClassNamesData *>(packet.get());

            cout << endl << "Packet Vehicle Class Names Data" << endl << endl;       

            for (size_t i = 0; i < p->class_info().size(); ++i) {
                cout << "Class Index    " << i << " " << p->class_info().at(i).class_index() << endl;
                cout << "Name           " << i << " " << p->class_info().at(i).name() << endl;
            }
         }
         ++packets_;
    }

    void MyProcessV2::menu(Packet::Ptr &)
    {
        cout << "Num Packets " << packets_ << endl;
    }

}