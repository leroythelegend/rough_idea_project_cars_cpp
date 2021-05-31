#include "../inc/decoderls2bits.h"

#include "../inc/exception.h"

namespace pcars {

DecoderLS2bits::DecoderLS2bits()
	: num_(0) {
}

DecoderLS2bits::~DecoderLS2bits() {
}


void DecoderLS2bits::decode(const PCars_Data & data, Position & position) {
	num_ = data.at(position) & 3;
}

unsigned int DecoderLS2bits::ls2bits() const {
	return num_;
}

}

