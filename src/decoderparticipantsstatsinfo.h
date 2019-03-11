#ifndef PCARS_PACKET_PARTICIPANTS_STATS_INFO_H_
#define PCARS_PACKET_PARTICIPANTS_STATS_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoderu16.h"
#include "decoderu32.h"
#include "decoderf32.h"

namespace pcars {

	/// \class DecoderParticipantsStatsInfo
	/// \brief Decode participants stats info

	class DecoderParticipantsStatsInfo : public DecoderComposite {
	public:

		/// Constructor
		DecoderParticipantsStatsInfo();
		/// Destructor
		virtual ~DecoderParticipantsStatsInfo() {}

		/// \brief Get Fastest lap time
		///
		/// \return Fastest lap time
		/// \throw nothing

		float fastest_lap_time() const;

		/// \brief Get last lap time
		///
		/// \return Last lap time
		/// \throw nothing

		float last_lap_time() const;

		/// \brief Get last sector time
		///
		/// \return Last sector time
		/// \throw nothing

		float last_sector_time() const;

		/// \brief Get Fastest sector 1 time
		///
		/// \return Fastest sector 1 time
		/// \throw nothing

		float fastest_sector1_time() const;

		/// \brief Get Fastest sector 2 time
		///
		/// \return Fastest sector 2 time
		/// \throw nothing

		float fastest_sector2_time() const;

		/// \brief Get Fastest sector 3 time
		///
		/// \return Fastest sector 3 time
		/// \throw nothing

		float fastest_sector3_time() const;

		/// \brief Get participant online rep
		///
		/// \return Participant online rep
		/// \throw nothing

		unsigned int participant_online_rep() const;

		/// \brief Get participant index
		///
		/// \return Participant index
		/// \throw nothing

		unsigned int  mp_participant_index() const;

	private:
		DecoderF32 fastest_lap_time_;
		DecoderF32 last_lap_time_;
		DecoderF32 last_sector_time_;
		DecoderF32 fastest_sector1_time_;
		DecoderF32 fastest_sector2_time_;
		DecoderF32 fastest_sector3_time_;
		DecoderU32 participant_online_rep_;
		DecoderU16 mp_participant_index_;
	};
}

#endif

