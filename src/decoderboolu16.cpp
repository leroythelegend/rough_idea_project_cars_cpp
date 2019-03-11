#include "decoderboolu16.h"

namespace pcars {

DecoderBoolU16::DecoderBoolU16() {
	add(&bool_);
	add(&num_);
}

void DecoderBoolU16::decode(const PCars_Data & data, Position & position) {
	DecoderComposite::decode(data, position);
}

bool DecoderBoolU16::msb_bool() const {
	return bool_.msb_bool();
}
unsigned int DecoderBoolU16::u15() const {
	return num_.u15();
}

}
