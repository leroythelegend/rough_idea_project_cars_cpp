#include "../inc/decoderf32.h"

#include "../inc/exception.h"

namespace pcars {

DecoderF32::DecoderF32()
	: num_{-1} {}

void DecoderF32::decode(const PCars_Data &data, Position &position) {

	uint32_t val = 	(data.at(position + 3) << 24) |
			(data.at(position + 2) << 16) |
			(data.at(position + 1) << 8)  |
			(data.at(position));

	union {
		uint32_t val;
		float f;
	} u = { val };

	num_ = u.f;

	position += 4;
}

float DecoderF32::f32() const {
	return num_;
}

}

