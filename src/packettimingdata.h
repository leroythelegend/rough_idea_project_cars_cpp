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

	///
	/// Packet timing data format 2
	///

	class PacketTimingData : public Packet {
	public:

		PacketTimingData();
		virtual ~PacketTimingData() noexcept = default;

        /// Packet Base		
		PacketBase packet_base() const;
		/// Number of Participants		
		int num_participants() const;
		/// ?
		unsigned int participants_changed_timestamp() const;
		/// Event Time Remaining
		float event_time_remaining() const;
		/// Split Time Ahead
		float split_time_ahead() const;
		/// Split Time Behind
		float split_time_behind() const;
		/// ?
		float split_time() const;
		/// Returns a Vector of Participant Info
		Decoder32ParticipantInfo::Vector_Participant_Info partcipants() const;
		/// I thing this is the local participant index to be used with the vector of Participant Info
		unsigned int local_participant_index() const;
		/// Tick Count something to keep packets in order
		unsigned int tick_count() const;
		/// Format version
		Format format() const override { return 2; }
		/// Type of Packet
		Type type() const override { return PACKETTYPE::PACKETTIMINGDATA;}

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

