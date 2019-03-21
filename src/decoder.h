#ifndef PCARS_DECODER_H_
#define PCARS_DECODER_H_

#include "consts.h"

namespace pcars {

	///
	///	Abstract Decodes Project Cars Data
	///

	class Decoder {
	public:
		virtual ~Decoder() noexcept {}

		///	Decodes PCars Data at position in Data
		virtual void decode(const PCars_Data &, Position &) = 0;
	};

}

#endif

