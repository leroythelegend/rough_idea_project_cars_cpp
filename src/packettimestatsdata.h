#ifndef PCARS_PACKET_TIME_STATS_DATA_H_
#define PCARS_PACKET_TIME_STATS_DATA_H_

#include "decodercomposite.h"

#include "consts.h"

#include "packetbase.h"

#include "decoderu32.h"
#include "decoder32participantsstatsinfo.h"

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

		Type type() const override { return "PacketTimeStatsData"; }

	private:

		PacketBase packet_base_;		
		DecoderU32 participants_changed_timestamp_;
		Decoder32ParticipantsStatsInfo stats_;
	};

}

#endif

