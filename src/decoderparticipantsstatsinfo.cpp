#include "decoderparticipantsstatsinfo.h"

namespace pcars {

DecoderParticipantsStatsInfo::DecoderParticipantsStatsInfo() {
	add(&fastest_lap_time_);
	add(&last_lap_time_);
	add(&last_sector_time_);
	add(&fastest_sector1_time_);
	add(&fastest_sector2_time_);
	add(&fastest_sector3_time_);
	add(&participant_online_rep_);
	add(&mp_participant_index_);
}

float DecoderParticipantsStatsInfo::fastest_lap_time() const {
	return fastest_lap_time_.f32();
}

float DecoderParticipantsStatsInfo::last_lap_time() const {
	return last_lap_time_.f32();
}

float DecoderParticipantsStatsInfo::last_sector_time() const {
	return last_sector_time_.f32();
}

float DecoderParticipantsStatsInfo::fastest_sector1_time() const {
	return fastest_sector1_time_.f32();
}

float DecoderParticipantsStatsInfo::fastest_sector2_time() const {
	return fastest_sector2_time_.f32();
}

float DecoderParticipantsStatsInfo::fastest_sector3_time() const {
	return fastest_sector3_time_.f32();
}

unsigned int DecoderParticipantsStatsInfo::participant_online_rep() const {
	return participant_online_rep_.u32();
}

unsigned int DecoderParticipantsStatsInfo::mp_participant_index() const {
	return mp_participant_index_.u16();
}

}


