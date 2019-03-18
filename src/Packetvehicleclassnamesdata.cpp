#include "packetvehicleclassnamesdata.h"

namespace pcars {

PacketVehicleClassNamesData::PacketVehicleClassNamesData() {
	add(&packet_base_);
	add(&class_info_);
}

PacketBase PacketVehicleClassNamesData::packet_base() const {
	return packet_base_;
}

Decoder60ClassInfo::Vector_Class_Info PacketVehicleClassNamesData::class_info() const {
	return class_info_.class_info();
}

}

