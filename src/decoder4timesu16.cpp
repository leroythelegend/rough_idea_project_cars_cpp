#include "../inc/decoder4timesu16.h"

namespace pcars {

Decoder4TimesU16::Decoder4TimesU16() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);
}

Vector_UInt Decoder4TimesU16::times4_u16() const {
	Vector_UInt value;
	value.push_back(first_.u16());
	value.push_back(second_.u16());
	value.push_back(third_.u16());
	value.push_back(forth_.u16());
	return value;
}

}
