#include "decoder3timesfloat.h"

namespace pcars {

Decoder3TimesFloat::Decoder3TimesFloat() {
	add(&first_);
	add(&second_);
	add(&third_);
}

Vector_Float Decoder3TimesFloat::times3_float() const {
	Vector_Float value;
	value.push_back(first_.f32());
	value.push_back(second_.f32());
	value.push_back(third_.f32());
	return value;
}

}

