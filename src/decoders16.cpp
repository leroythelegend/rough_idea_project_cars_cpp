#include "decoders16.h"

#include "exception.h"

namespace pcars {

DecoderS16::DecoderS16()
	: num_(0) {
}

DecoderS16::~DecoderS16() {
}

void DecoderS16::decode(const PCars_Data & data, Position & position) {

	num_ = ((data.at(position + 1) << 8) | data.at(position));

	position += 2;
}

int DecoderS16::s16() const {
	return num_;
}

}

