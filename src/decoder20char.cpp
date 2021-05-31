#include "../inc/decoder20char.h"

#include "../inc/exception.h"

#include <iostream>

using namespace std;

namespace pcars {

Decoder20Char::Decoder20Char() {
}

void Decoder20Char::decode(const PCars_Data & data, Position & position) {

	char20_.assign(data.begin() + position, data.begin() + (position + 20));

	// cout << char20_ << endl;

	position += 20; 
}

std::string Decoder20Char::char20() const {
	std::string str = char20_;
	return str.substr(0, str.find('\0'));
}

}

