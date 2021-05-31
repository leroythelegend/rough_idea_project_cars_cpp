#include "../inc/decoderstringvector.h"
#include "../inc/decoder64char.h"
#include "../inc/exception.h"

namespace pcars {


DecoderStringVector::DecoderStringVector(int numparticipants) 
	: numparticipants_(numparticipants < 16 ? numparticipants : 16) {
}

DecoderStringVector::~DecoderStringVector() {
}

void DecoderStringVector::decode(const PCars_Data & data, Position & position) {

	for (int8_t i = 0; i < numparticipants_; ++i) {
		Decoder64Char cdecoder;
		cdecoder.decode(data, position);
		stringvector_.push_back(cdecoder.char64());
	}
}

Vector_String DecoderStringVector::string_vector() const {
	return stringvector_;
}


}
