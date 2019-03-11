#ifndef PCARS_PACKET_32_PARTICIPANT_INFO_H_
#define PCARS_PACKET_32_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "decoderparticipantinfo.h"

namespace pcars {

	/// \class Decoder32ParticipantInfo
	/// \brief Decode 32 participant info into vector

	class Decoder32ParticipantInfo : public DecoderComposite {
	public:
		using Vector_Participant_Info = std::vector<DecoderParticipantInfo>;

		/// Constructor
		Decoder32ParticipantInfo();
		/// Destructor
		virtual ~Decoder32ParticipantInfo() {}

		/// \brief Get participant info vector
		///
		/// \return Participant info vector
		/// \throw nothing

		Vector_Participant_Info participant_info() const;

	private:

		Vector_Participant_Info particpantsinfo_;
	};

}

#endif

