#include "../inc/decoderms4bits.h"

#include "../inc/exception.h"

namespace pcars {

DecoderMS4bits::DecoderMS4bits()
	: num_(0) {
}

DecoderMS4bits::~DecoderMS4bits() {
}

void DecoderMS4bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 4) & 15;
}

unsigned int DecoderMS4bits::ms4bits() const {
	return num_;
}

}

