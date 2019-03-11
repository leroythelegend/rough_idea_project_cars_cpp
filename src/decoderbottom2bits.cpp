#include "decoderbottom2bits.h"

namespace pcars {

DecoderBottom2bits::DecoderBottom2bits()
	: num_{0} {

}

void DecoderBottom2bits::decode(const PCars_Data & data, Position & position) {
	num_ = ((data.at(position) >> 3) & 3);
}

unsigned int DecoderBottom2bits::bottom_2bit() const {
	return num_;
}

}

