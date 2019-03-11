#include "decoder2bit3bit.h"

namespace pcars {

Decoder2bit3bit::Decoder2bit3bit() {
	add(&ms2bits_);
	add(&ls3bits_);
}

void Decoder2bit3bit::decode(const PCars_Data & data, Position & position) {
	DecoderComposite::decode(data, position);
	++position;
}

unsigned int Decoder2bit3bit::ms2bits() const {
	return ms2bits_.ms2bits();
}

unsigned int Decoder2bit3bit::ls3bits() const {
	return ls3bits_.ls3bits();
}

}
