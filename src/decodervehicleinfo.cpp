#include "../inc/decodervehicleinfo.h"

namespace pcars {


DecoderVehicleInfo::DecoderVehicleInfo() {
	add(&index_);
	add(&class_);
	add(&name_);
}

unsigned int DecoderVehicleInfo::index() const {
	return index_.u16();
}

unsigned int DecoderVehicleInfo::class_name() const {
	return class_.u32();
}

std::string DecoderVehicleInfo::name() const {
	return name_.char64();
}

}

