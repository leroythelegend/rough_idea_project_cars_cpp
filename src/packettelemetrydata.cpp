#include "packettelemetrydata.h"

namespace pcars {

PacketTelemetryData::PacketTelemetryData() {
	add(&packet_base_);
	add(&viewed_participant_index_);
	add(&unfiltered_throttle_);
	add(&unfiltered_brake_);
	add(&unfiltered_steering_);
	add(&unfiltered_clutch_);
	add(&car_flags_);	
	add(&oil_temp_celsius_);
	add(&oil_pressure_kpa_);
	add(&water_temp_celsius_);
	add(&water_pressure_kpa_);
	add(&fuel_pressure_kpa_);
	add(&fuel_capacity_);
	add(&brake_);
	add(&throttle_);
	add(&clutch_);
	add(&fuel_level_);
	add(&speed_);
	add(&rpm_);
	add(&max_rpm_);
	add(&steering_);
	add(&gear_num_gears_);
	add(&boost_amount_);
	add(&crash_state_);
	add(&odometer_km_);
	add(&orientation_);
	add(&local_velocity_);
	add(&world_velocity_);
	add(&angular_velocity_);
	add(&local_acceleration_);
	add(&world_acceleration_);
	add(&extents_centre_);
	add(&tyre_flags_);
	add(&terrain_);
	add(&tyre_y_);
	add(&tyre_rps_);
	add(&tyre_temp_);
	add(&tyre_height_above_ground_);
	add(&tyre_wear_);
	add(&brake_damage_);
	add(&suspension_damage_);
	add(&brake_temp_celsius_);
	add(&tyre_tread_temp_);
	add(&tyre_layer_temp_);
	add(&tyre_carcass_temp_);
	add(&tyre_rim_temp_);
	add(&tyre_internal_air_temp_);
	add(&tyre_temp_left_);
	add(&tyre_temp_center_);
	add(&tyre_temp_right_);	
	add(&wheel_local_position_y_);
	add(&ride_height_);
	add(&suspension_travel_);
	add(&suspension_velocity_);
	add(&suspension_ride_height_);
	add(&air_pressure_);
	add(&engine_speed_);
	add(&engine_torque_);
	add(&wings_);
	add(&handbrake_);
	add(&aero_damage_);
	add(&engine_damage_);
	add(&joy_pad_0_);
	add(&d_pad_);
	add(&tyre_compound_);
	add(&turbo_boost_pressure_);
	add(&full_position_);
	add(&brake_bias_);
	add(&tick_count_);
}

PacketBase PacketTelemetryData::packet_base() const {
	return packet_base_;
}

int PacketTelemetryData::viewed_participant_index() const {
	return viewed_participant_index_.s8();
}

unsigned int PacketTelemetryData::unfiltered_throttle() const {
	return unfiltered_throttle_.u8();
}

unsigned int PacketTelemetryData::unfiltered_brake() const {
	return unfiltered_brake_.u8();
}

int PacketTelemetryData::unfiltered_steering() const {
	return unfiltered_steering_.s8();
}

unsigned int PacketTelemetryData::unfiltered_clutch() const {
	return unfiltered_clutch_.u8();
}

unsigned int PacketTelemetryData::car_flags() const {
	return car_flags_.u8();
}

int PacketTelemetryData::oil_temp_celsius() const {
	return oil_temp_celsius_.s16();
}

unsigned int PacketTelemetryData::oil_pressure_kpa() const {
	return oil_pressure_kpa_.u16();
}

int PacketTelemetryData::water_temp_celsius() const {
	return water_temp_celsius_.s16();
}

unsigned int PacketTelemetryData::water_pressure_kpa() const {
	return water_pressure_kpa_.u16();
}

unsigned int PacketTelemetryData::fuel_pressure_kpa() const {
	return fuel_pressure_kpa_.u16();
}

unsigned int PacketTelemetryData::fuel_capacity() const {
	return fuel_capacity_.u8();
}

unsigned int PacketTelemetryData::brake() const {
	return brake_.u8();
}

unsigned int PacketTelemetryData::throttle() const {
	return throttle_.u8();
}

unsigned int PacketTelemetryData::clutch() const {
	return clutch_.u8();
}

float PacketTelemetryData::fuel_level() const {
	return fuel_level_.f32();
}

float PacketTelemetryData::speed() const {
	return speed_.f32();
}

unsigned int PacketTelemetryData::rpm() const {
	return rpm_.u16();
}

unsigned int PacketTelemetryData::max_rpm() const {
	return max_rpm_.u16();
}

int PacketTelemetryData::steering() const {
	return steering_.s8();
}

unsigned int PacketTelemetryData::gears() const {
	return gear_num_gears_.ms4bits();
}

unsigned int PacketTelemetryData::gear() const {
	return gear_num_gears_.ls4bits();
}

unsigned int PacketTelemetryData::boost_amount() const {
	return boost_amount_.u8();
}

unsigned int PacketTelemetryData::crash_state() const {
	return crash_state_.u8();
}

float PacketTelemetryData::odometer_km() const {
	return odometer_km_.f32();
}

Vector_Float PacketTelemetryData::orientation() const {
	return orientation_.times3_float();
}

Vector_Float PacketTelemetryData::local_velocity() const {
	return local_velocity_.times3_float();
}

Vector_Float PacketTelemetryData::world_velocity() const {
	return world_velocity_.times3_float();
}

Vector_Float PacketTelemetryData::angular_velocity() const {
	return angular_velocity_.times3_float();
}

Vector_Float PacketTelemetryData::local_acceleration() const {
	return local_acceleration_.times3_float();
}

Vector_Float PacketTelemetryData::world_acceleration() const {
	return world_acceleration_.times3_float();
}

Vector_Float PacketTelemetryData::extents_centre() const {
	return extents_centre_.times3_float();
}

Vector_UInt PacketTelemetryData::tyre_flags() const {
	return tyre_flags_.times4_u8();
}

Vector_UInt PacketTelemetryData::terrain() const {
	return terrain_.times4_u8();
}

Vector_Float PacketTelemetryData::tyre_y() const {
	return tyre_y_.times4_float();
}

Vector_Float PacketTelemetryData::tyre_rps() const {
	return tyre_rps_.times4_float();
}

Vector_UInt PacketTelemetryData::tyre_temp() const {
	return tyre_temp_.times4_u8();
}
Vector_Float PacketTelemetryData::tyre_height_above_ground() const {
	return tyre_height_above_ground_.times4_float();
}

Vector_UInt PacketTelemetryData::tyre_wear() const {
	return tyre_wear_.times4_u8();
}

Vector_UInt PacketTelemetryData::brake_damage() const {
	return brake_damage_.times4_u8();
}

Vector_UInt PacketTelemetryData::suspension_damage() const {
	return suspension_damage_.times4_u8();
}

Vector_Int PacketTelemetryData::brake_temp_celsius() const {
	return brake_temp_celsius_.times4_s16();
}

Vector_UInt PacketTelemetryData::tyre_tread_temp() const {
	return tyre_tread_temp_.times4_u16();
}

Vector_UInt PacketTelemetryData::tyre_layer_temp() const {
	return tyre_layer_temp_.times4_u16();
}

Vector_UInt PacketTelemetryData::tyre_carcass_temp() const {
	return tyre_carcass_temp_.times4_u16();
}

Vector_UInt PacketTelemetryData::tyre_rim_temp() const {
	return tyre_rim_temp_.times4_u16();
}

Vector_UInt PacketTelemetryData::tyre_internal_air_temp() const {
	return tyre_internal_air_temp_.times4_u16();
}

Vector_UInt PacketTelemetryData::tyre_temp_left() const {
	return tyre_temp_left_.times4_u16();
}

Vector_UInt PacketTelemetryData::tyre_temp_center() const {
	return tyre_temp_center_.times4_u16();
}

Vector_UInt PacketTelemetryData::tyre_temp_right() const {
	return tyre_temp_right_.times4_u16();
}

Vector_Float PacketTelemetryData::wheel_local_position_y() const {
	return wheel_local_position_y_.times4_float();
}

Vector_Float PacketTelemetryData::ride_height() const {
	return ride_height_.times4_float();
}

Vector_Float PacketTelemetryData::suspension_travel() const {
	return suspension_travel_.times4_float();
}

Vector_Float PacketTelemetryData::suspension_velocity() const {
	return suspension_velocity_.times4_float();
}

Vector_UInt PacketTelemetryData::suspension_ride_height() const {
	return suspension_ride_height_.times4_u16();
}

Vector_UInt PacketTelemetryData::air_pressure() const {
	return air_pressure_.times4_u16();
}

float PacketTelemetryData::engine_speed() const {
	return engine_speed_.f32();
}

float PacketTelemetryData::engine_torque() const {
	return engine_torque_.f32();
}

Vector_UInt PacketTelemetryData::wings() const {
	return wings_.times2_U8();
}

unsigned int PacketTelemetryData::handbrake() const {
	return handbrake_.u8();
}

unsigned int PacketTelemetryData::aero_damage() const {
	return aero_damage_.u8();
}

unsigned int PacketTelemetryData::engine_damage() const {
	return engine_damage_.u8();
}

unsigned int PacketTelemetryData::joy_pad_0() const {
	return joy_pad_0_.u32();
}

unsigned int PacketTelemetryData::d_pad() const {
	return d_pad_.u8();
}

Vector_String PacketTelemetryData::tyre_compound() const {
	return tyre_compound_.times4_40Char();
}

float PacketTelemetryData::turbo_boost_pressure() const {
	return turbo_boost_pressure_.f32();
}

Vector_Float PacketTelemetryData::full_position() const {
	return full_position_.times3_float();
}

unsigned int PacketTelemetryData::brake_bias() const {
	return brake_bias_.u8();
}

unsigned int PacketTelemetryData::tick_count() const {
	return tick_count_.u32();
}

}
