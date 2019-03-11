#ifndef PCARS_PACKET_TIMING_DATA_H_
#define PCARS_PACKET_TIMING_DATA_H_

#include "packet.h"

#include "consts.h"

#include "packetbase.h"
#include "decoder32participantinfo.h"

#include "decoder3timess16.h"
#include "decoderu16.h"
#include "decoderf32.h"
#include "decoders8.h"

namespace pcars {

	/// \class PacketTimingData
	/// \brief Packet timing data format 2

	class PacketTimingData : public Packet {
	public:

		/// Constructor
		PacketTimingData();
		/// Destructor
		virtual ~PacketTimingData() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing
		
		PacketBase packet_base() const;		
		int num_participants() const;
		unsigned int participants_changed_timestamp() const;
		float event_time_remaining() const;
		float split_time_ahead() const;
		float split_time_behind() const;
		float split_time() const;
		Decoder32ParticipantInfo::Vector_Participant_Info partcipants() const;
		unsigned int local_participant_index() const;
		unsigned int tick_count() const;
        
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
		
		Type type() const override { return "PacketTimingData";}

	private:

		PacketBase packet_base_;		
		DecoderS8 num_participants_;
		DecoderU32 participants_changed_timestamp_;
		DecoderF32 event_time_remaining_;
		DecoderF32 split_time_ahead_;
		DecoderF32 split_time_behind_;
		DecoderF32 split_time_;
		Decoder32ParticipantInfo partcipants_;
		DecoderU16 local_participant_index_;
		DecoderU32 tick_count_;
	};

}

#endif

