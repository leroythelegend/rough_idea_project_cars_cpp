#include "../inc/decoderls4bits.h"

#include "../inc/exception.h"

namespace pcars {

DecoderLS4bits::DecoderLS4bits()
	: num_(0) {
}

DecoderLS4bits::~DecoderLS4bits() {
}

void DecoderLS4bits::decode(const PCars_Data & data, Position & position) {
	num_ = data.at(position) & 15;
}

unsigned int DecoderLS4bits::ls4bits() const {
	return num_;
}

}

