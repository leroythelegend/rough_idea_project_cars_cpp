#include "../inc/decodermsbbool.h"

namespace pcars {

DecoderMSBBool::DecoderMSBBool()
	: num_(true) {
}

DecoderMSBBool::~DecoderMSBBool() {
}

void DecoderMSBBool::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 7);
}

bool DecoderMSBBool::msb_bool() const {
	return num_;
}

}

