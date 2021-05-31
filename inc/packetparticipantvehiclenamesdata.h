#ifndef PCARS_PACKET_PARTICIPANTS_VEHICLE_NAMES_DATA_H_
#define PCARS_PACKET_PARTICIPANTS_VEHICLE_NAMES_DATA_H_

#include "../inc/packet.h"

#include "../inc/consts.h"

#include "../inc/packetbase.h"

#include "../inc/decoderu32.h"
#include "../inc/decoder16vehicleinfo.h"

namespace pcars {

	/// \class PacketParticipantsVehicleNamesData
	/// \brief Packet participants vehicle names data
	class PacketParticipantsVehicleNamesData : public Packet {
	public:

		/// Constructor
		PacketParticipantsVehicleNamesData();
		/// Destructor
		virtual ~PacketParticipantsVehicleNamesData() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing
		
		PacketBase packet_base() const;

		/// \brief Get vehicle info
		///
		/// \return Vehicle info
		/// \throw nothing

		Decoder16VehicleInfo::Vector_Vehicle_Info vehicle_info() const;

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

		Type type() const override { return PACKETTYPE::PACKETPARTICIPANTSVEHICLENAMESDATA; }

	private:
		PacketBase packet_base_;		
		Decoder16VehicleInfo vehicle_info_;
	};

}

#endif

