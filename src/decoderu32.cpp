#include "../inc/decoderu32.h"

#include "../inc/exception.h"

namespace pcars {

DecoderU32::DecoderU32()
	: num_{0} {}

void DecoderU32::decode(const PCars_Data & data, Position & position) {

	num_ = 	(data.at(position + 3) << 24) |
			(data.at(position + 2) << 16) |
			(data.at(position + 1) << 8)  |
			 data.at(position);

	position += 4;
}

unsigned int DecoderU32::u32() const {
	return num_;
}

}

