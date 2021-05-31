#include "../inc/decoder32participantinfo.h"

namespace pcars {

Decoder32ParticipantInfo::Decoder32ParticipantInfo() 
	: particpantsinfo_(32) {
	for (unsigned int i = 0; i < particpantsinfo_.size(); ++i) {
		add(&particpantsinfo_.at(i));
	}
}

Decoder32ParticipantInfo::Vector_Participant_Info Decoder32ParticipantInfo::participant_info() const {
	return particpantsinfo_;
}

}
