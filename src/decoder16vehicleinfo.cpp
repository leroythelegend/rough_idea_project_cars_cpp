#include "decoder16vehicleinfo.h"

namespace pcars {

Decoder16VehicleInfo::Decoder16VehicleInfo()
	: vehicle_info_(16) {
	for (unsigned int i = 0; i < vehicle_info_.size(); ++i) {
		add(&vehicle_info_.at(i));
	}
}

Decoder16VehicleInfo::Vector_Vehicle_Info Decoder16VehicleInfo::vehicle_info() const {
	return vehicle_info_;
}

}

