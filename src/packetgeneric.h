#ifndef PCARS_PACKET_GENERIC_H_
#define PCARS_PACKET_GENERIC_H_

#include "packet.h"

#include "decoderu16.h"
#include "decoder6bit2bit.h"

namespace pcars {

	/// \class PacketGeneric
	/// \brief Format 1 Generic packet

	class PacketGeneric : public Packet {
	public:
		/// Constructor
		PacketGeneric();
		/// Destructor
		virtual ~PacketGeneric();

		/// \brief Get build version
		///
		/// \return Build version
		/// \throw nothing

		uint16_t build_version() const;

		/// \brief Get sequence number
		///
		/// \return Sequence number
		/// \throw nothing

		unsigned int sequence_number() const;

		/// \brief Get packet type
		///
		/// \return Packet type
		/// \throw nothing

		Packet_Type packet_type() const;

        /// \brief Get packet format
        ///
        ///     format 1
        ///
        /// \return Format
        /// \throw nothing

		Format format() const override { return 1;};

		/// \brief Get packet type
        ///
        ///
        /// \return Packet type
        /// \throw nothing

		Type type() const override { return "Decoder_Generic";};

	private:
		DecoderU16 buildversion_;
		Decoder6bit2bit sequencenum_packettype_;
	};

}

#endif

