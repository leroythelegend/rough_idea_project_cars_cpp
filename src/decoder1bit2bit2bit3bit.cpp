#include "../inc/decoder1bit2bit2bit3bit.h"

namespace pcars {

Decoder1bit2bit2bit3bit::Decoder1bit2bit2bit3bit() {
	add(&lsb3bit_);
	add(&b2bit_);
	add(&t2bit_);
	add(&msb1bit_);
}

void Decoder1bit2bit2bit3bit::decode(const PCars_Data &data, unsigned int &position) {
	DecoderComposite::decode(data, position);
	++position;
}

unsigned int Decoder1bit2bit2bit3bit::lsb_3bit() const {
	return lsb3bit_.ls3bits();
}

unsigned int Decoder1bit2bit2bit3bit::bottom_2bit() const {
	return b2bit_.bottom_2bit();
}

unsigned int Decoder1bit2bit2bit3bit::top_2bit() const {
	return t2bit_.top_2bit();
}

bool Decoder1bit2bit2bit3bit::msb_1bit() const {
	return msb1bit_.msb_bool();
}


}

