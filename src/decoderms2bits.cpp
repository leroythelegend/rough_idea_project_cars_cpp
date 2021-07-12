#include "../inc/decoderms2bits.h"



namespace pcars {

DecoderMS2bits::DecoderMS2bits()
	: num_{0} {
}

void DecoderMS2bits::decode(const PCars_Data & data, Position & position) {
	num_ = (data.at(position) >> 4) & 3;
}

unsigned int DecoderMS2bits::ms2bits() const {
	return num_;
}

}

