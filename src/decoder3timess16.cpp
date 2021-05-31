#include "../inc/decoder3timess16.h"

namespace pcars {

Decoder3TimesS16::Decoder3TimesS16() {
	add(&first_);
	add(&second_);
	add(&third_);
}

Vector_Int Decoder3TimesS16::times3_s16() const {
	Vector_Int value;
	value.push_back(first_.s16());
	value.push_back(second_.s16());
	value.push_back(third_.s16());
	return value;
}

}
