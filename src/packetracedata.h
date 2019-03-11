#ifndef PCARS_PACKET_RACE_DATA_H_
#define PCARS_PACKET_RACE_DATA_H_

#include <string>

#include "packet.h"

#include "consts.h"

#include "packetbase.h"
#include "decoder32participantinfo.h"

#include "decoderu16.h"
#include "decoderf32.h"
#include "decoders8.h"
#include "decoder64char.h"

namespace pcars {

	/// \class PacketRaceData
	/// \brief Packet race data

	class PacketRaceData : public Packet {
	public:

		/// Constructor
		PacketRaceData();
		/// Destructor
		virtual ~PacketRaceData() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing

		PacketBase packet_base() const;

		float world_fastest_lap_time() const;
		float personal_fastest_lap_time() const;	
		float personal_fastest_sector1_time() const;
		float personal_fastest_sector2_time() const;
		float personal_fastest_sector3_time() const;
		float world_fastest_sector1_time() const;
		float world_fastest_sector2_time() const;
		float world_fastest_sector3_time() const;
		float track_length() const;
		std::string track_location() const;	
		std::string track_variation() const;	
		std::string translated_track_location() const;
		std::string translated_track_variation() const;
		unsigned int laps_time_in_event() const;
		int enforced_pitstop_lap() const;

        /// \brief Get packet format
        ///
        ///     format 2
        ///
        /// \return Format
        /// \throw nothing

		Format format() const override { return 2; }

		/// \brief Get packet type
        ///
        ///
        /// \return Packet type
        /// \throw nothing

		Type type() const override { return "PacketRaceData"; }

	private:

		PacketBase packet_base_;		
		DecoderF32 world_fastest_lap_time_;
		DecoderF32 personal_fastest_lap_time_;	
		DecoderF32 personal_fastest_sector1_time_;
		DecoderF32 personal_fastest_sector2_time_;
		DecoderF32 personal_fastest_sector3_time_;
		DecoderF32 world_fastest_sector1_time_;
		DecoderF32 world_fastest_sector2_time_;
		DecoderF32 world_fastest_sector3_time_;
		DecoderF32 track_length_;
		Decoder64Char track_location_;	
		Decoder64Char track_variation_;	
		Decoder64Char translated_track_location_;
		Decoder64Char translated_track_variation_;
		DecoderU16 laps_time_in_event_;
		DecoderS8 enforced_pitstop_lap_;

	};

}

#endif

