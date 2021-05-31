#ifndef PCARS_PACKET_PARTICIPANTS_DATA_H_
#define PCARS_PACKET_PARTICIPANTS_DATA_H_

#include "../inc/packet.h"

#include "../inc/consts.h"

#include "../inc/packetbase.h"

#include "../inc/decoderu16.h"
#include "../inc/decoderu32.h"
#include "../inc/decoder16timeschar64.h"
#include "../inc/decoder16timesu32.h"
#include "../inc/decoder16timesu16.h"

namespace pcars {

	/// \class PacketParticipantsData
	/// \brief Packet Participant data

	class PacketParticipantsData : public Packet {
	public:

		/// Constructor
		PacketParticipantsData();
		/// Destructor
		virtual ~PacketParticipantsData() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing

		PacketBase packet_base() const;	

		/// \brief Get participants changed timestamp
		///
		/// \return Timestamp
		/// \throw nothing

		unsigned int participants_changed_timestamp() const;

		/// \brief Get names
		///
		/// \return Names
		/// \throw nothing

		Vector_String name() const;
		
		/// \brief Get nationality
		///
		/// \return Nationality
		/// \throw nothing

		Vector_UInt nationality() const;

		/// \brief Get index
		///
		/// \return Index
		/// \throw nothing

		Vector_UInt index() const;

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
			
		Type type() const override { return PACKETTYPE::PACKETPARTICIPANTSDATA; }

	private:

		PacketBase packet_base_;		
		DecoderU32 participants_changed_timestamp_;
		Decoder16Times64Char name_;
		Decoder16TimesU32 nationality_;
		Decoder16TimesU16 index_;

	};

}

#endif

