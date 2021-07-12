#include "../inc/decoderms6bits.h"



namespace pcars {

DecoderMS6bits::DecoderMS6bits()
	: num_(0) {

}

DecoderMS6bits::~DecoderMS6bits() {
}

void DecoderMS6bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 2);
}

unsigned int DecoderMS6bits::ms6bits() const {
	return num_;
}

}

