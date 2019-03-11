#ifndef PCARS_DEOCDER_PARTICIPANT_INFO_H_
#define PCARS_DEOCDER_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoder1bit2bit2bit3bit.h"
#include "decoderu8.h"
#include "decoderf32.h"
#include "decoderboolu8.h"

namespace pcars {

	/// \class DecoderParticipantInfoV1
	/// \brief Decode participant info

	class DecoderParticipantInfoV1 : public DecoderComposite {
	public:
		/// Constructor
		DecoderParticipantInfoV1();
		/// Destructor
		virtual ~DecoderParticipantInfoV1();

		/// \brief Get vector of world position
		///
		///		Returns x,y and z of world position
		///
		/// \return value
		/// \throw nothing
	
		Vector_Int world_position() const;

		/// \brief Get current lap distance
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int current_lap_distance() const;

		/// \brief Get participant active
		///
		///
		/// \return value
		/// \throw nothing

		bool is_active() const;

		/// \brief Get race position
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int race_position() const;

		/// \brief Participants lap in invalid
		///
		///
		/// \return value
		/// \throw nothing

		bool lap_invalidated() const;

		/// \brief Get number of laps completed
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int laps_completed() const;

		/// \brief Get current lap
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int current_lap() const;

		/// \brief Participant has same class
		///
		///
		/// \return value
		/// \throw nothing

		bool same_class() const;

		/// \brief Finer world postion z
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int world_positionZ() const;

		/// \brief Finer world postion x
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int world_positionX() const;

		/// \brief Get current sector
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int sector() const;

		/// \brief Get last sector time
		///
		///
		/// \return value
		/// \throw nothing

		float last_sector_time() const;

	private:
		Decoder3TimesS16 worldposition_;
		DecoderU16 currentlapdistance_;
		DecoderBoolU8 raceposition_;
		DecoderBoolU8 lapscompleted_;
		DecoderU8 currentlap_;
		Decoder1bit2bit2bit3bit sector_;
		DecoderF32 lastsectortime_;
	};

}

#endif

