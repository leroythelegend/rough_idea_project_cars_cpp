#include "../inc/decoderparticipantinfo.h"

namespace pcars {
	
DecoderParticipantInfo::DecoderParticipantInfo() {
	add(&world_position_);
	add(&orientation_);
	add(&current_lap_distance_);
	add(&race_position_);
	add(&sector_);
	add(&highest_flag_);
	add(&pit_mode_schedule_);
	add(&car_index_);
	add(&race_state_);
	add(&current_lap_);
	add(&current_time_);
	add(&current_sector_time_);
	add(&mp_participant_index_);
}

Vector_Int DecoderParticipantInfo::world_position() const {
	return world_position_.times3_s16();
}

Vector_Int DecoderParticipantInfo::orientation() const {
	return orientation_.times3_s16();
}

unsigned int DecoderParticipantInfo::current_lap_distance() const {
	return current_lap_distance_.u16();
}

bool DecoderParticipantInfo::is_active() const {
	return race_position_.msb_bool();
}

unsigned int DecoderParticipantInfo::race_position() const {
	return race_position_.ls7_bits();
}

unsigned int DecoderParticipantInfo::zx_position() const {
	return sector_.ms4bits();
}

unsigned int DecoderParticipantInfo::sector() const {
	return sector_.ls4bits();
}

unsigned int DecoderParticipantInfo::flag_colour() const {
	return highest_flag_.ms3bits();
}

unsigned int DecoderParticipantInfo::flag_reason() const {
	return highest_flag_.ls3bits();
}
unsigned int DecoderParticipantInfo::pit_mode() const {
	return pit_mode_schedule_.ls4bits();
}

unsigned int DecoderParticipantInfo::pit_mode_schedule() const {
	return pit_mode_schedule_.ms4bits();
}

unsigned int DecoderParticipantInfo::car_index() const {
	return car_index_.u15();
}

bool DecoderParticipantInfo::local_player() const {
	return car_index_.msb_bool();
}

bool DecoderParticipantInfo::remote_player() const {
	return car_index_.msb_bool();
}

bool DecoderParticipantInfo::human_player() const {
	return car_index_.msb_bool();
}

bool DecoderParticipantInfo::none_human_player() const {
	return car_index_.msb_bool();
}

unsigned int DecoderParticipantInfo::race_state() const {
	return race_state_.ls7_bits();
}

bool DecoderParticipantInfo::invalid_lap() const {
	return car_index_.msb_bool();
}

unsigned int DecoderParticipantInfo::current_lap() const {
	return current_lap_.u8();
}

float DecoderParticipantInfo::current_time() const {
	return current_time_.f32();
}

float DecoderParticipantInfo::current_sector_time() const {
	return current_sector_time_.f32();
}

unsigned int DecoderParticipantInfo::mp_participant_index() const {
	return mp_participant_index_.u16();
}

}


