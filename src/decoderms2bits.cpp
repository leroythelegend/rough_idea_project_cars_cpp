#include "decoderms2bits.h"

#include "exception.h"

namespace pcars {

DecoderMS2bits::DecoderMS2bits()
	: num_{0} {
}

void DecoderMS2bits::decode(const PCars_Data & data, Position & position) {
	num_ = data.at(position) & 48;
}

unsigned int DecoderMS2bits::ms2bits() const {
	return num_;
}

}

