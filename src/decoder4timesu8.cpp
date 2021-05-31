#include "../inc/decoder4timesu8.h"

namespace pcars {

Decoder4TimesU8::Decoder4TimesU8() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);

}

Vector_UInt Decoder4TimesU8::times4_u8() const {
	Vector_UInt value;
	value.push_back(first_.u8());
	value.push_back(second_.u8());
	value.push_back(third_.u8());
	value.push_back(forth_.u8());
	return value;
}

}

