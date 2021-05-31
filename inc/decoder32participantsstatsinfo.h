#ifndef PCARS_PACKET_32_PARTICIPANTS_STATS_INFO_H_
#define PCARS_PACKET_32_PARTICIPANTS_STATS_INFO_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoderparticipantsstatsinfo.h"

namespace pcars {

	/// \class Decoder32ParticipantsStatsInfo
	/// \brief Decode 32 participant stats info into a vector

	class Decoder32ParticipantsStatsInfo : public DecoderComposite {
	public:
		using Vector_Participants_Stats_Info = std::vector<DecoderParticipantsStatsInfo>;

		/// Constructor
		Decoder32ParticipantsStatsInfo();
		/// Destructor
		virtual ~Decoder32ParticipantsStatsInfo() {}

		/// \brief Get participants stats info vector
		///
		///
		/// \return participants stats info vector
		/// \throw nothing
		
		Vector_Participants_Stats_Info participants_stats_info() const;

	private:

		Vector_Participants_Stats_Info particpants_stats_info_;
	};

}

#endif

