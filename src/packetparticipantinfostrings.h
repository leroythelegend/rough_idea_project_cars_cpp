#ifndef PCARS_DECODER_PARTICIPANT_INFO_STRINGS_H_
#define PCARS_DECODER_PARTICIPANT_INFO_STRINGS_H_

#include "packet.h"
#include "decoderu16.h"
#include "decoder6bit2bit.h"
#include "decoder64char.h"
#include "decoderstringvector.h"
#include "decoder16timesfloat.h"

#include <string>
#include <vector>

namespace pcars {

	/// \class PacketParticipantInfoStrings
	/// \brief Packet Participant Info Strings

	class PacketParticipantInfoStrings : public Packet {
	public:

		/// Construtors
		PacketParticipantInfoStrings();
		/// Destructor
		virtual ~PacketParticipantInfoStrings() {};

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

		/// \brief Get car name
		///
		///
		/// \return value
		/// \throw nothing

		std::string car_name() const;

		/// \brief Get car class name
		///
		///
		/// \return value
		/// \throw nothing

		std::string car_class_name() const;

		/// \brief Get track loation
		///
		///
		/// \return value
		/// \throw nothing

		std::string track_location() const;

		/// \brief Get track variation
		///
		///
		/// \return value
		/// \throw nothing

		std::string track_variation() const;

		/// \brief Get vector names
		///
		///		This vector ONLY holds 16 names 
	    ///     Need to use the extended info strings packet NOT
		///     implemented yet (soon)
		///
		/// \return value
		/// \throw nothing

		Vector_String names() const;

		/// \brief Fastest Lap Times
		///
		///		This vector ONLY holds 16 names 
	    ///     Need to use the extended info strings packet NOT
		///     implemented yet (soon)
		///
		/// \return value
		/// \throw nothing

		Vector_Float fastest_lap_times() const;

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

		Type type() const override { return  PACKETTYPE::PACKETPARTICIPANTINFOSTRINGS; } 

	private:
		DecoderU16 buildversion_;
		Decoder6bit2bit sequencenum_packettype_;
		Decoder64Char carname_;
		Decoder64Char carclassname_;
		Decoder64Char tracklocation_;
		Decoder64Char trackvariation_;
		DecoderStringVector names_;
		Decoder16TimesFloat fastest_lap_times_;
	};

}

#endif

