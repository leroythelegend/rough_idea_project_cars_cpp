#include "../inc/decoders8.h"

#include "../inc/exception.h"

namespace pcars {

DecoderS8::DecoderS8()
	: num_(0) {
}

DecoderS8::~DecoderS8() {
}

void DecoderS8::decode(const PCars_Data & data, Position & position) {

	num_ = data.at(position);

	++position;
}

int DecoderS8::s8() const {
	return num_;
}

}

