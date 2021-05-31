#ifndef PCARS_PACKET_TIME_STATS_DATA_H_
#define PCARS_PACKET_TIME_STATS_DATA_H_

#include "../inc/decodercomposite.h"

#include "../inc/consts.h"

#include "../inc/packetbase.h"

#include "../inc/decoderu32.h"
#include "../inc/decoder32participantsstatsinfo.h"

namespace pcars {


	/// \class PacketTimeStatsData
	/// \brief Packet time stats data format 2

	class PacketTimeStatsData : public Packet {
	public:

		PacketTimeStatsData();
		virtual ~PacketTimeStatsData() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing
		
		PacketBase packet_base() const;		
		unsigned int participants_changed_timestamp() const;
		Decoder32ParticipantsStatsInfo::Vector_Participants_Stats_Info stats() const;

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

		Type type() const override { return PACKETTYPE::PACKETTIMESTATSDATA; }

	private:

		PacketBase packet_base_;		
		DecoderU32 participants_changed_timestamp_;
		Decoder32ParticipantsStatsInfo stats_;
	};

}

#endif

