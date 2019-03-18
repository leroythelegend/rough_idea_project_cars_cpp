#ifndef PCARS_PACKET_VEHICLE_CLASS_NAMES_DATA_H_
#define PCARS_PACKET_VEHICLE_CLASS_NAMES_DATA_H_

#include "packet.h"

#include "consts.h"

#include "packetbase.h"

#include "decoderu32.h"
#include "decoder60classinfo.h"

namespace pcars {

	/// \class PacketVehicleClassNamesData
	/// \brief Packet participants vehicle names data
	class PacketVehicleClassNamesData : public Packet {
	public:

		/// Constructor
		PacketVehicleClassNamesData();
		/// Destructor
		virtual ~PacketVehicleClassNamesData() {}

		/// \brief Get packet base
		///
		/// \return Packet base
		/// \throw nothing
		
		PacketBase packet_base() const;

		/// \brief Get vehicle info
		///
		/// \return Vehicle info
		/// \throw nothing

		Decoder60ClassInfo::Vector_Class_Info class_info() const;

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

		Type type() const override { return "PacketVehicleClassNamesData"; }

	private:
		PacketBase packet_base_;		
		Decoder60ClassInfo class_info_;
	};

}

#endif

