#ifndef PCARS_PACKET_BASE_H_
#define PCARS_PACKET_BASE_H_

#include "packet.h"

#include "decoderu32.h"
#include "decoderu8.h"

#include <string>

namespace pcars {


	/// \class PacketBase
	/// \brief Decode format 2 base packet

	class PacketBase : public Packet {
	public:

		/// Constructor
		PacketBase();
		/// Destructor
		virtual ~PacketBase() {}

		/// \brief Get packet number
		///
		/// \return Packet Number
		/// \throw nothing

		unsigned int packet_number() const;

		/// \brief Get category packet number
		///
		/// \return Category packet number
		/// \throw nothing

		unsigned int category_packet_number() const;
		
		/// \brief Get partial packet index
		///
		/// \return Partial packet index
		/// \throw nothing

		unsigned int partial_packet_index() const;
		
		/// \brief Get Partial packet number
		///
		/// \return Partial packet number
		/// \throe nothing

		unsigned int partial_packet_number() const;

		/// \brief Get Packet type
		///
		/// \return Packet type
		/// \throe nothing

		unsigned int packet_type() const;

		/// \brief Get Packet version
		///
		/// \return Packet version
		/// \throe nothing

		unsigned int packet_version() const;

        /// \brief Get packet format
        ///
        ///     Either format 1 or 2
        ///
        /// \return Format
        /// \throw nothing

		Format format() const override { return 2; };

		/// \brief Get packet type
        ///
        ///
        /// \return Packet type
        /// \throw nothing

		Type type() const override { return PACKETTYPE::PACKETBASE; }
		
	private:

		DecoderU32 packet_number_;
		DecoderU32 category_packet_number_;
		DecoderU8 partial_packet_index_;
		DecoderU8 partial_packet_number_;
		DecoderU8 packet_type_;
		DecoderU8 packet_version_;
	};

}

#endif

