#include "../inc/decoder4timesfloat.h"

namespace pcars {

Decoder4TimesFloat::Decoder4TimesFloat() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);
}

Vector_Float Decoder4TimesFloat::times4_float() const {
	Vector_Float value;
	value.push_back(first_.f32());
	value.push_back(second_.f32());
	value.push_back(third_.f32());
	value.push_back(forth_.f32());
	return value;
}

}

