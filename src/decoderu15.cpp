#include "../inc/decoderu15.h"



namespace pcars {

DecoderU15::DecoderU15()
	: num_(0) {
}

DecoderU15::~DecoderU15() {
}

void DecoderU15::decode(const PCars_Data & data, Position & position) {

	num_ = ((data.at(position + 1) << 8) | (data.at(position) & 127));

	position += 2;
}

unsigned int DecoderU15::u15() const {
	return num_;
}

}

