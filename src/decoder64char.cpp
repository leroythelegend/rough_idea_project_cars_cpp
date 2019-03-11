#include "decoder64char.h"

#include "exception.h"

namespace pcars {

Decoder64Char::Decoder64Char() {
}

void Decoder64Char::decode(const PCars_Data & data, Position & position) {

	char64_.assign(data.begin() + position, data.begin() + (position + 64));

	position += 64; 
}

std::string Decoder64Char::char64() const {
	std::string str = char64_;
	return str.substr(0, str.find('\0'));
}

}

