#include "../inc/decoderls7bits.h"
#include <iostream>

namespace pcars {

DecoderLS7bits::DecoderLS7bits()
	: num_(0) {

}

DecoderLS7bits::~DecoderLS7bits() {
}

void DecoderLS7bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) & 127);
}

unsigned int DecoderLS7bits::ls7bits() const {
	return num_;
}

}

