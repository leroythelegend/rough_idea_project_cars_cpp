#include "packettimingdata.h"

namespace pcars {

PacketTimingData::PacketTimingData() {

	add(&packet_base_);
	add(&num_participants_);
	add(&participants_changed_timestamp_);
	add(&event_time_remaining_);
	add(&split_time_ahead_);
	add(&split_time_behind_);
	add(&split_time_);
	add(&partcipants_);
	add(&local_participant_index_);
	add(&tick_count_);
}

PacketBase PacketTimingData::packet_base() const {
	return packet_base_;
}

int PacketTimingData::num_participants() const {
	return num_participants_.s8(); 
}

unsigned int PacketTimingData::participants_changed_timestamp() const {
	return participants_changed_timestamp_.u32(); 
}

float PacketTimingData::event_time_remaining() const {
	return event_time_remaining_.f32(); 
}

float PacketTimingData::split_time_ahead() const {
	return split_time_ahead_.f32(); 
}

float PacketTimingData::split_time_behind() const {
	return split_time_behind_.f32(); 
}

float PacketTimingData::split_time() const {
	return split_time_.f32(); 
}

Decoder32ParticipantInfo::Vector_Participant_Info PacketTimingData::partcipants() const {
	return partcipants_.participant_info() ; 
}

unsigned int PacketTimingData::local_participant_index() const {
	return 0; 
}

unsigned int PacketTimingData::tick_count() const {
	return tick_count_.u32(); 
}


}

