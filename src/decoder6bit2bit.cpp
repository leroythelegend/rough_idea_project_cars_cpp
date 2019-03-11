#include "decoder6bit2bit.h"

namespace pcars {

Decoder6bit2bit::Decoder6bit2bit() {
	add(&ms6bits_);
	add(&ls2bits_);
}

void Decoder6bit2bit::decode(const PCars_Data & data, Position & position) {
	DecoderComposite::decode(data, position);
	++position;
}

unsigned int Decoder6bit2bit::ms6bits() const {
	return ms6bits_.ms6bits();
}

unsigned int Decoder6bit2bit::ls2bits() const {
	return ls2bits_.ls2bits();
}

}
