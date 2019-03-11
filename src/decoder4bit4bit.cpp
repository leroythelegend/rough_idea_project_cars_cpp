#include "decoder4bit4bit.h"

namespace pcars {

Decoder4bit4bit::Decoder4bit4bit() {
	add(&ms4bits_);
	add(&ls4bits_);
}

void Decoder4bit4bit::decode(const PCars_Data & data, Position & position) {
	DecoderComposite::decode(data, position);
	++position;
}

unsigned int Decoder4bit4bit::ms4bits() const {
	return ms4bits_.ms4bits();
}

unsigned int Decoder4bit4bit::ls4bits() const {
	return ls4bits_.ls4bits();
}

}
