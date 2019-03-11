#include "packetparticipantvehiclenamesdata.h"

namespace pcars {

PacketParticipantsVehicleNamesData::PacketParticipantsVehicleNamesData() {
	add(&packet_base_);
	add(&vehicle_info_);
}

PacketBase PacketParticipantsVehicleNamesData::packet_base() const {
	return packet_base_;
}

Decoder16VehicleInfo::Vector_Vehicle_Info PacketParticipantsVehicleNamesData::vehicle_info() const {
	return vehicle_info_.vehicle_info();
}

}

