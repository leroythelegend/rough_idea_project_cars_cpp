#include "../inc/decoderu16.h"

#include "../inc/exception.h"

namespace pcars {

DecoderU16::DecoderU16()
	: num_(0) {
}

DecoderU16::~DecoderU16() {
}

void DecoderU16::decode(const PCars_Data & data, Position & position) {

	num_ = ((data.at(position + 1) << 8) | (data.at(position)));

	position += 2;
}

unsigned int DecoderU16::u16() const {
	return num_;
}

}

