#include "../inc/decoder3bit.h"

namespace pcars {

Decoder3bit::Decoder3bit() {
	add(&ls3bits_);
}

void Decoder3bit::decode(const PCars_Data &data, Position &position) {
	DecoderComposite::decode(data, position);
	++position;
}

unsigned int Decoder3bit::ls3bits() const {
	return ls3bits_.ls3bits();
}

}
