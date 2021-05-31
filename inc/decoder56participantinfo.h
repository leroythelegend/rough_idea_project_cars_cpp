#ifndef PCARS_DECODER_56_PARTICIPANT_INFO_H_
#define PCARS_DECODER_56_PARTICIPANT_INFO_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoderparticipantinfov1.h"

namespace pcars {

	/// \class Decoder56ParticipantInfo
	/// \brief Decode 56 participant info

	class Decoder56ParticipantInfo : public DecoderComposite {
	public:
		using Vector_Participant_Info = std::vector<DecoderParticipantInfoV1>;

		/// Constructor
		Decoder56ParticipantInfo();
		/// Destructor
		virtual ~Decoder56ParticipantInfo() {}

		/// \brief Get vector of participant info
		///
		///
		/// \return value
		/// \throw nothing

		Vector_Participant_Info participant_info() const;

	private:

		Vector_Participant_Info particpantsinfo_;
	};

}

#endif

