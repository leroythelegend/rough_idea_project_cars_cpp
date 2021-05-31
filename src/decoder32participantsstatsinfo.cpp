#include "../inc/decoder32participantsstatsinfo.h"

namespace pcars {

Decoder32ParticipantsStatsInfo::Decoder32ParticipantsStatsInfo() 
	: particpants_stats_info_(32) {
	for (unsigned int i = 0; i < particpants_stats_info_.size(); ++i) {
		add(&particpants_stats_info_.at(i));
	}
}

Decoder32ParticipantsStatsInfo::Vector_Participants_Stats_Info Decoder32ParticipantsStatsInfo::participants_stats_info() const {
	return particpants_stats_info_;
}

}
