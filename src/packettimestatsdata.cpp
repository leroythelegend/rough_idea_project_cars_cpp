#include "packettimestatsdata.h"

namespace pcars {

	PacketTimeStatsData::PacketTimeStatsData() {
	add(&packet_base_);		
	add(&participants_changed_timestamp_);
	add(&stats_);
}

PacketBase PacketTimeStatsData::packet_base() const	 {
	return packet_base_;
}

unsigned int PacketTimeStatsData::participants_changed_timestamp() const {
	return participants_changed_timestamp_.u32();
}

Decoder32ParticipantsStatsInfo::Vector_Participants_Stats_Info PacketTimeStatsData::stats() const {
	return stats_.participants_stats_info();
}



}


