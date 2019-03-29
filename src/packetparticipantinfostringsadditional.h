#ifndef PCARS_DECODER_PARTICIPANT_INFO_STRINGS_ADDITIONAL_H_
#define PCARS_DECODER_PARTICIPANT_INFO_STRINGS_ADDITIONAL_H_

#include "packet.h"
#include "decoderu16.h"
#include "decoder6bit2bit.h"
#include "decoderu8.h"
#include "decoderstringvector.h"

#include <string>
#include <vector>

namespace pcars {

	/// \class PacketParticipantInfoStringsAdditional
	/// \brief Packet Participant Info Strings Additional

	class PacketParticipantInfoStringsAdditional : public Packet {
	public:

		/// Construtors
		PacketParticipantInfoStringsAdditional();
		/// Destructor
		virtual ~PacketParticipantInfoStringsAdditional() {};

		/// \brief Get build version
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int build_version() const;

		/// \brief Get sequence number
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int sequence_number() const;

		unsigned int packet_type() const;

		unsigned int offset() const;

		/// \brief Get vector names
		///
        ///
		///
		/// \return value
		/// \throw nothing

		Vector_String names() const;

		/// \brief Get project cars format version
		///
		///
		/// \return value
		/// \throw nothing

		Format format() const override { return 1; }

		/// \brief Get packet type
		///
		///
		/// \return value
		/// \throw nothing

		Type type() const override { return PACKETTYPE::PACKETPARTICIPANTINFOSTRINGSADDITIONAL; } 

	private:
		DecoderU16 buildversion_;
		Decoder6bit2bit sequencenum_packettype_;
        DecoderU8 offset_;
        DecoderStringVector names_;
	};

}

#endif

