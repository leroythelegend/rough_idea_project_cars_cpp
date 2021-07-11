#include "../inc/decoderls3bits.h"



namespace pcars {

DecoderLS3bits::DecoderLS3bits()
	: num_(0) {

}

DecoderLS3bits::~DecoderLS3bits() {
}

void DecoderLS3bits::decode(const PCars_Data & data, Position & position) {
	num_ = data.at(position) & 7;
}

unsigned int DecoderLS3bits::ls3bits() const {
	return num_;
}

}

