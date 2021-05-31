#include "../inc/decoderboolu8.h"

namespace pcars {

DecoderBoolU8::DecoderBoolU8() {
	add(&bool_);
	add(&num_);
}

void DecoderBoolU8::decode(const PCars_Data & data, Position & position) {
	DecoderComposite::decode(data, position);
	++position;
}

bool DecoderBoolU8::msb_bool() const {
	return bool_.msb_bool();
}
unsigned int DecoderBoolU8::ls7_bits() const {
	return num_.ls7bits();
}

}

