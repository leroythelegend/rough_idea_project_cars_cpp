#include "../inc/decoder16timesfloat.h"

namespace pcars {

Decoder16TimesFloat::Decoder16TimesFloat() {
	add(&first_);
	add(&second_);
	add(&third_);
	add(&forth_);
	add(&fifth_);
	add(&sixth_);
	add(&seventh_);
	add(&eighth_);
	add(&ninth_);
	add(&tenth_);
	add(&eleventh_);
	add(&twelve_);
	add(&thirteen_);
	add(&forteen_);
	add(&fifteen_);
	add(&sixteen_);

}

Vector_Float Decoder16TimesFloat::times16_float() const {
	Vector_Float value;
	value.push_back(first_.f32());
	value.push_back(second_.f32());
	value.push_back(third_.f32());
	value.push_back(forth_.f32());
    value.push_back(fifth_.f32());
    value.push_back(sixth_.f32());
    value.push_back(seventh_.f32());
    value.push_back(eighth_.f32());
    value.push_back(ninth_.f32());
    value.push_back(tenth_.f32());
    value.push_back(eleventh_.f32());
    value.push_back(twelve_.f32());
    value.push_back(thirteen_.f32());
    value.push_back(forteen_.f32());
    value.push_back(fifteen_.f32());
    value.push_back(sixteen_.f32());

	return value;
}

}

