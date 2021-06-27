#include "../inc/packettelemetrydatav1.h"

namespace pcars {

PacketTelemetryDataV1::PacketTelemetryDataV1() {
	add(&buildversion_);
	add(&sequencenum_packettype_);
	add(&sessionstate_gamestate_);
	add(&viewedparticipantindex_);
	add(&numparticipants_);
	add(&unfilteredthrottle_);
	add(&unfilteredbrake_);
	add(&unfilteredsteering_);
	add(&unfilteredclutch_);
	add(&racestateflags_);
	add(&lapsinevent_);
	add(&bestlaptime_);
	add(&lastlaptime_);
	add(&currenttime_);
	add(&splittimeahead_);
	add(&splittimebehind_);
	add(&splittime_);
	add(&eventtimeremaining_);
	add(&personalfastestlaptime_);
	add(&worldfastestlaptime_);
	add(&currentsector1time_);
	add(&currentsector2time_);
	add(&currentsector3time_);
	add(&fastestsector1time_);
	add(&fastestsector2time_);
	add(&fastestsector3time_);
	add(&personalfastestsector1time_);
	add(&personalfastestsector2time_);
	add(&personalfastestsector3time_);
	add(&worldfastestsector1time_);
	add(&worldfastestsector2time_);
	add(&worldfastestsector3time_);
	add(&joypad_);
	add(&highestflagreason_highestflagcolour_);
	add(&pitschedule_pitmode_);
	add(&oiltempcelsius_);
	add(&oilpressurekpa_);
	add(&watertempcelsius_);
	add(&waterpressurekpa_);
	add(&fuelpressurekpa_);
	add(&carflags_);
	add(&fuelcapacity_);
	add(&brake_);
	add(&throttle_);
	add(&clutch_);
	add(&steering_);
	add(&fuellevel_);
	add(&speed_);
	add(&rpm_);
	add(&maxrpm_);
	add(&gearnumgears_);
	add(&boostamount_);
	add(&enforcedpitstoplap_);
	add(&crashstate_);
	add(&odometerkm_);
	add(&orientation_);
	add(&localvelocity_);
	add(&worldvelocity_);
	add(&angularvelocity_);
	add(&localacceleration_);
	add(&worldacceleration_);
	add(&extentscentre_);
	add(&tyreflags_);
	add(&terrain_);
	add(&tyrey_);
	add(&tyrerps_);
	add(&tyreslipspeed_);
	add(&tyretemp_);
	add(&tyregrip_);
	add(&tyreheightaboveground_);
	add(&tyrelateralstiffness_);
	add(&tyrewear_);
	add(&brakedamage_);
	add(&suspensiondamage_);
	add(&braketempcelsius_);
	add(&tyretreadtemp_);
	add(&tyrelayertemp_);
	add(&tyrecarcasstemp_);
	add(&tyrerimtemp_);
	add(&tyreinternalairtemp_);
	add(&wheellocalpositiony_);
	add(&rideheight_);
	add(&suspensiontravel_);
	add(&suspensionvelocity_);
	add(&airpressure_);
	add(&enginespeed_);
	add(&enginetorque_);
	add(&aerodamage_);
	add(&enginedamage_);
	add(&ambienttemperature_);
	add(&tracktemperature_);
	add(&raindensity_);
	add(&windspeed_);
	add(&winddirectionx_);
	add(&winddirectiony_);
	add(&paricipantinfo_);
	add(&tracklength_);
	add(&wings_);
	add(&dpad_);
}

PacketTelemetryDataV1::~PacketTelemetryDataV1() {
}

unsigned int PacketTelemetryDataV1::build_version() const {
	return buildversion_.u16();
}

unsigned int PacketTelemetryDataV1::sequence_number() const {
	return sequencenum_packettype_.ms6bits();
}

unsigned int PacketTelemetryDataV1::packet_type() const{
	return sequencenum_packettype_.ls2bits();
}

unsigned int PacketTelemetryDataV1::session_state() const {
	return sessionstate_gamestate_.ms3bits();
}

unsigned int PacketTelemetryDataV1::game_state() const {
	return sessionstate_gamestate_.ls3bits();
}

int PacketTelemetryDataV1::viewed_participant_index() const {
	return viewedparticipantindex_.s8();
}

int PacketTelemetryDataV1::num_participants() const {
	return numparticipants_.s8();
}

unsigned int PacketTelemetryDataV1::unfiltered_throttle() const {
	return unfilteredthrottle_.u8();
}

unsigned int PacketTelemetryDataV1::unfiltered_brake() const {
	return unfilteredbrake_.u8();
}

int PacketTelemetryDataV1::unfiltered_steering() const {
	return unfilteredsteering_.s8();
}

unsigned int PacketTelemetryDataV1::unfiltered_clutch() const {
	return unfilteredclutch_.u8();
}

unsigned int PacketTelemetryDataV1::race_state_flags() const {
	return racestateflags_.ls3bits();
}

unsigned int PacketTelemetryDataV1::laps_in_event() const {
	return lapsinevent_.u8();
}

float PacketTelemetryDataV1::best_lap_time() const {
	return bestlaptime_.f32();
}

float PacketTelemetryDataV1::last_lap_time() const {
	return lastlaptime_.f32();
}

float PacketTelemetryDataV1::current_time() const {
	return currenttime_.f32();
}

float PacketTelemetryDataV1::split_time_ahead() const {
	return splittimeahead_.f32();
}

float PacketTelemetryDataV1::split_time_behind() const {
	return splittimebehind_.f32();
}

float PacketTelemetryDataV1::split_time() const {
	return splittime_.f32();
}

float PacketTelemetryDataV1::event_time_remaining() const {
	return eventtimeremaining_.f32();
}

float PacketTelemetryDataV1::personal_fastest_lap_time() const {
	return personalfastestlaptime_.f32();
}

float PacketTelemetryDataV1::world_fastest_lap_time() const {
	return worldfastestlaptime_.f32();
}

float PacketTelemetryDataV1::current_sector1_time() const {
	return currentsector1time_.f32();
}

float PacketTelemetryDataV1::current_sector2_time() const {
	return currentsector2time_.f32();
}

float PacketTelemetryDataV1::current_sector3_time() const {
	return currentsector3time_.f32();
}

float PacketTelemetryDataV1::fastest_sector1_time() const {
	return fastestsector1time_.f32();
}

float PacketTelemetryDataV1::fastest_sector2_time() const {
	return fastestsector2time_.f32();
}

float PacketTelemetryDataV1::fastest_sector3_time() const {
	return fastestsector3time_.f32();
}

float PacketTelemetryDataV1::personal_fastest_sector1_time() const {
	return personalfastestsector1time_.f32();
}

float PacketTelemetryDataV1::personal_fastest_sector2_time() const {
	return personalfastestsector2time_.f32();
}

float PacketTelemetryDataV1::personal_fastest_sector3_time() const {
	return personalfastestsector3time_.f32();
}

float PacketTelemetryDataV1::world_fastest_sector1_time() const {
	return worldfastestsector1time_.f32();
}

float PacketTelemetryDataV1::world_fastest_sector2_time() const {
	return worldfastestsector2time_.f32();
}

float PacketTelemetryDataV1::world_fastest_sector3_time() const {
	return worldfastestsector3time_.f32();
}

unsigned int PacketTelemetryDataV1::joy_pad() const {
	return joypad_.u16();
}

unsigned int PacketTelemetryDataV1::flag_reason() const {
	return highestflagreason_highestflagcolour_.ls3bits();
}

unsigned int PacketTelemetryDataV1::flag_colour() const {
	return highestflagreason_highestflagcolour_.ms2bits();
}

unsigned int PacketTelemetryDataV1::pit_mode() const {
	return pitschedule_pitmode_.ls3bits();
}

unsigned int PacketTelemetryDataV1::pit_schedule() const {
	return pitschedule_pitmode_.ms2bits();
}

float PacketTelemetryDataV1::oil_temp_celsius() const {
	return static_cast<float>(oiltempcelsius_.s16());
}

float PacketTelemetryDataV1::oil_pressure_kpa() const {
	return static_cast<float>(oilpressurekpa_.u16());
}

float PacketTelemetryDataV1::water_temp_celsius() const {
	return static_cast<float>(watertempcelsius_.s16());
}

float PacketTelemetryDataV1::water_pressure_kpa() const {
	return static_cast<float>(oilpressurekpa_.u16());
}

float PacketTelemetryDataV1::fuel_pressure_kpa() const {
	return static_cast<float>(fuelpressurekpa_.u16());
}

unsigned int PacketTelemetryDataV1::car_flags() const {
	return carflags_.u8();
}

unsigned int PacketTelemetryDataV1::fuel_capacity() const {
	return fuelcapacity_.u8();
}

unsigned int PacketTelemetryDataV1::brake() const {
	return brake_.u8();
}

unsigned int PacketTelemetryDataV1::throttle() const {
	return throttle_.u8();
}

unsigned int PacketTelemetryDataV1::clutch() const {
	return clutch_.u8();
}

int PacketTelemetryDataV1::steering() const {
	return steering_.s8();
}

float PacketTelemetryDataV1::fuel_level() const {
	return fuellevel_.f32();
}

float PacketTelemetryDataV1::speed() const {
	return speed_.f32();
}

unsigned int PacketTelemetryDataV1::rpm() const {
	return rpm_.u16();
}

unsigned int PacketTelemetryDataV1::max_rpm() const {
	return maxrpm_.u16();
}

int PacketTelemetryDataV1::num_gears() const {
	return gearnumgears_.ms4bits();
}

int PacketTelemetryDataV1::gear() const {
	return gearnumgears_.ls4bits();
}

float PacketTelemetryDataV1::boost_amount() const {
	return static_cast<float>(boostamount_.u8());
}

int PacketTelemetryDataV1::enforced_pit_stop_lap() const {
	return enforcedpitstoplap_.s8();
}

unsigned int PacketTelemetryDataV1::crash_state() const {
	return crashstate_.ls3bits();
}

float PacketTelemetryDataV1::odometer_km() const {
	return odometerkm_.f32();
}

Vector_Float PacketTelemetryDataV1::orientation() const {
	return orientation_.times3_float();
}

Vector_Float PacketTelemetryDataV1::local_velocity() const {
	return localvelocity_.times3_float();
}

Vector_Float PacketTelemetryDataV1::world_velocity() const {
	return worldvelocity_.times3_float();
}

Vector_Float PacketTelemetryDataV1::angular_velocity() const {
	return angularvelocity_.times3_float();
}

Vector_Float PacketTelemetryDataV1::local_acceleration() const {
	return localacceleration_.times3_float();
}

Vector_Float PacketTelemetryDataV1::world_acceleration() const {
	return worldacceleration_.times3_float();
}

Vector_Float PacketTelemetryDataV1::extents_centre() const {
	return extentscentre_.times3_float();
}

Vector_UInt PacketTelemetryDataV1::tyre_flags() const {
	return tyreflags_.times4_u8();
}

Vector_UInt PacketTelemetryDataV1::terrain() const {
	return terrain_.times4_u8();
}

Vector_Float PacketTelemetryDataV1::tyre_y() const {
	return tyrey_.times4_float();
}

Vector_Float PacketTelemetryDataV1::tyre_rps() const {
	return tyrerps_.times4_float();
}

Vector_Float PacketTelemetryDataV1::tyre_slip_speed() const {
	return tyreslipspeed_.times4_float();
}

Vector_UInt PacketTelemetryDataV1::tyre_temp() const {
	return tyretemp_.times4_u8();
}

Vector_UInt PacketTelemetryDataV1::tyre_grip() const {
	return tyregrip_.times4_u8();
}

Vector_Float PacketTelemetryDataV1::tyre_height_above_ground() const {
	return tyreheightaboveground_.times4_float();
}

Vector_Float PacketTelemetryDataV1::tyre_lateral_stiffness() const {
	return tyrelateralstiffness_.times4_float();
}

Vector_UInt PacketTelemetryDataV1::tyre_wear() const {
	return tyrewear_.times4_u8();
}

Vector_UInt PacketTelemetryDataV1::brake_damage() const {
	return brakedamage_.times4_u8();
}

Vector_UInt PacketTelemetryDataV1::suspension_damage() const {
	return suspensiondamage_.times4_u8();
}

Vector_Int PacketTelemetryDataV1::brake_temp_celsius() const {
	return braketempcelsius_.times4_s16();
}

Vector_UInt PacketTelemetryDataV1::tyre_tread_temp() const {
	return tyretreadtemp_.times4_u16();
}

Vector_UInt PacketTelemetryDataV1::tyre_layer_temp() const {
	return tyrelayertemp_.times4_u16();
}

Vector_UInt PacketTelemetryDataV1::tyre_carcass_temp() const {
	return tyrecarcasstemp_.times4_u16();
}

Vector_UInt PacketTelemetryDataV1::tyre_rim_temp() const {
	return tyrerimtemp_.times4_u16();
}

Vector_UInt PacketTelemetryDataV1::tyre_internal_air_temp() const {
	return tyreinternalairtemp_.times4_u16();
}

Vector_Float PacketTelemetryDataV1::wheel_local_position_y() const {
	return wheellocalpositiony_.times4_float();
}

Vector_Float PacketTelemetryDataV1::ride_height() const {
	return rideheight_.times4_float();
}

Vector_Float PacketTelemetryDataV1::suspension_travel() const {
	return suspensiontravel_.times4_float();
}

Vector_Float PacketTelemetryDataV1::suspension_velocity() const {
	return suspensionvelocity_.times4_float();
}

Vector_UInt PacketTelemetryDataV1::air_pressure() const {
	return airpressure_.times4_u16();
}

float PacketTelemetryDataV1::engine_speed() const {
	return enginespeed_.f32();
}

float PacketTelemetryDataV1::engine_torque() const {
	return enginetorque_.f32();
}

float PacketTelemetryDataV1::aero_damage() const {
	return static_cast<float>(aerodamage_.u8());
}

float PacketTelemetryDataV1::engine_damage() const {
	return static_cast<float>(enginedamage_.u8());
}

float PacketTelemetryDataV1::ambient_temperature() const {
	return static_cast<float>(ambienttemperature_.s8());
}

float PacketTelemetryDataV1::track_temperature() const {
	return static_cast<float>(tracktemperature_.s8());
}

float PacketTelemetryDataV1::rain_density() const {
	return static_cast<float>(raindensity_.u8());
}

float PacketTelemetryDataV1::wind_speed() const {
	return static_cast<float>(windspeed_.s8());
}

float PacketTelemetryDataV1::wind_direction_x() const {
	return static_cast<float>(winddirectionx_.s8());
}

float PacketTelemetryDataV1::wind_direction_y() const {
	return static_cast<float>(winddirectiony_.s8());
}

PacketTelemetryDataV1::Vector_Participant_Info PacketTelemetryDataV1::participant_info() const {
	return paricipantinfo_.participant_info();
}

float PacketTelemetryDataV1::track_length() const {
	return tracklength_.f32();
}

Vector_UInt PacketTelemetryDataV1::wings() const {
	return wings_.times2_U8();
}

unsigned int PacketTelemetryDataV1::dpad() const {
	return dpad_.u8();
}

}

