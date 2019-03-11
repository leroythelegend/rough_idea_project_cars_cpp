#include "decoderu8.h"

#include "exception.h"

namespace pcars {

DecoderU8::DecoderU8()
	: num_(0) {
}

DecoderU8::~DecoderU8() {
}

void DecoderU8::decode(const PCars_Data & data, Position & position) {

	num_ = data.at(position);
	++position;
}

unsigned int DecoderU8::u8() const {
	return num_;
}

}

