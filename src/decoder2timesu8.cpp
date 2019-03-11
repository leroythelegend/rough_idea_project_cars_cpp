#include "decoder2timesu8.h"

namespace pcars {

Decoder2TimesU8::Decoder2TimesU8() {
	add(&first_);
	add(&second_);

}

Decoder2TimesU8::~Decoder2TimesU8() {

}

Vector_UInt Decoder2TimesU8::times2_U8() const {
	Vector_UInt value;
	value.push_back(first_.u8());
	value.push_back(second_.u8());
	return value;
}

}

