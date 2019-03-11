#include "decoder3bit3bit.h"

namespace pcars {

Decoder3bit3bit::Decoder3bit3bit() {
	add(&ms3bits_);
	add(&ls3bits_);
}

void Decoder3bit3bit::decode(const PCars_Data &data, Position &position) {
	DecoderComposite::decode(data, position);
	++position;
}

unsigned int Decoder3bit3bit::ms3bits() const {
	return ms3bits_.ms3bits();
}

unsigned int Decoder3bit3bit::ls3bits() const {
	return ls3bits_.ls3bits();
}

}

