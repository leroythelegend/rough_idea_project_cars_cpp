#include "decodertop2bits.h"

namespace pcars {

DecoderTop2bits::DecoderTop2bits()
	: num_(0) {
}

DecoderTop2bits::~DecoderTop2bits() {
}

void DecoderTop2bits::decode(const PCars_Data & data, Position & position) {
	num_ = ((data.at(position) >> 5) & 3);
}

unsigned int DecoderTop2bits::top_2bit() const {
	return num_;
}

}

