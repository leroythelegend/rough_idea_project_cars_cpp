#include "../inc/decoderms3bits.h"

#include "../inc/exception.h"

namespace pcars {

DecoderMS3bits::DecoderMS3bits()
	: num_(0) {
}

DecoderMS3bits::~DecoderMS3bits() {
}

void DecoderMS3bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 4) & 7;
}

unsigned int DecoderMS3bits::ms3bits() const {
	return num_;
}

}

