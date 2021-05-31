#include "../inc/decoder56participantinfo.h"

namespace pcars {

Decoder56ParticipantInfo::Decoder56ParticipantInfo() 
	: particpantsinfo_(56) {
	for (unsigned int i = 0; i < particpantsinfo_.size(); ++i) {
		add(&particpantsinfo_.at(i));
	}
}

Decoder56ParticipantInfo::Vector_Participant_Info Decoder56ParticipantInfo::participant_info() const {
	return particpantsinfo_;
}

}
