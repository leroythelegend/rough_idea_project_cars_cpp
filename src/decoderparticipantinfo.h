#ifndef PCARS_PACKET_PARTICIPANT_INFO_H_
#define PCARS_PACKET_PARTICIPANT_INFO_H_

#include "decodercomposite.h"

#include "consts.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoderf32.h"
#include "decoderu8.h"
#include "decoder3bit3bit.h"
#include "decoder4bit4bit.h"
#include "decoderboolu8.h"
#include "decoderboolu16.h"
#include "decoder4bit4bit.h"

namespace pcars {

	/// \class DecoderParticipantInfo
	/// \brief Decode participant info

	class DecoderParticipantInfo : public DecoderComposite {
	public:

		/// Constructor
		DecoderParticipantInfo();
		/// Destructor
		virtual ~DecoderParticipantInfo() {}

		/// \brief Get World Position
		///
		/// \return World position
		/// \throw nothing

		Vector_Int world_position() const;
		
		/// \brief Get Orientation
		///
		/// \return Orientation
		/// \throw nothing		
		
		Vector_Int orientation() const;

		/// \brief Get Current lap distance
		///
		/// \return Current lap distance
		/// \throw nothing		
		
		unsigned int current_lap_distance() const;

		/// \brief Get race position
		///
		/// \return Race position
		/// \throw nothing

		unsigned int race_position() const;
		
		/// \brief Participant is active
		///
		/// \return is active
		/// \throw nothing

		bool is_active() const;
		
		/// \brief Get zx position
		///
		/// \return zx position
		/// \throw nothing

		unsigned int zx_position() const;

	    /// \brief Get Current sector
		///
		/// \return sector
		/// \throw nothing

		unsigned int sector() const;
		
		/// \brief Get flag colour
		///
		/// \return flag colour
		/// \throw nothing

		unsigned int flag_colour() const;

		/// \brief Get flag reason
		///
		/// \return flag reason
		/// \throw nothing

		unsigned int flag_reason() const;

		/// \brief Get pit mode
		///
		/// \return pit mode
		/// \throw nothing

		unsigned int pit_mode() const;

		/// \brief Get pit mode schedule
		///
		/// \return Pit mode schedule
		/// \throw nothing

		unsigned int pit_mode_schedule() const;

		/// \brief Get car index
		///
		/// \return Car index
		/// \throw nothing

		unsigned int car_index() const;
		
		/// \brief Is local player
		///
		/// \return Local player
		/// \throw nothing

		bool local_player() const;

		/// \brief Is remote player
		///
		/// \return Remote player
		/// \throw nothing

		bool remote_player() const;
		
		/// \brief Is human player
		///
		/// \return human player
		/// \throw nothing

		bool human_player() const;
		
		/// \brief Is non human player
		///
		/// \return non human player
		/// \throw nothing

		bool none_human_player() const;

		/// \brief Get race state
		///
		/// \return Race state
		/// \throw nothing

		unsigned int race_state() const;

		/// \brief Is invalid lap
		///
		/// \return Invalid lap
		/// \throw nothing

		bool invalid_lap() const;

		/// \brief Get current lap
		///
		/// \return Current lap
		/// \throw nothing

		unsigned int current_lap() const;
		
		/// \brief Get current time
		///
		/// \return current time
		/// \throw nothing

		float current_time() const;

		/// \brief Get current sector time
		///
		/// \return current sector time
		/// \throw nothing
		
		float current_sector_time() const;
		
		/// \brief Get mp participant index
		///
		/// \return particpant index
		/// \throw nothing	
		
		unsigned int mp_participant_index() const;

	private:
		Decoder3TimesS16 world_position_;
		Decoder3TimesS16 orientation_;
		DecoderU16 current_lap_distance_;
		DecoderBoolU8 race_position_;
		Decoder4bit4bit sector_;
		Decoder3bit3bit highest_flag_;
		Decoder4bit4bit pit_mode_schedule_;
		DecoderBoolU16 car_index_;
		DecoderBoolU8 race_state_;
		DecoderU8 current_lap_;
		DecoderF32 current_time_;
		DecoderF32 current_sector_time_;
		DecoderU16 mp_participant_index_;
	};

}

#endif

