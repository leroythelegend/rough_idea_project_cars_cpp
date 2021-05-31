#ifndef PCARS_DECODER_H_
#define PCARS_DECODER_H_

#include "../inc/consts.h"

namespace pcars {

	///
	///	Abstract Decodes Project Cars Data
	///

	class Decoder {
	public:
		virtual ~Decoder() noexcept = default;

		///	Decodes PCars Data at position in Data
		/// \param PCars_Data:
		/// \param[in/out] Position: Position in PCars_Data
		virtual void decode(const PCars_Data &, Position &) = 0;
	};

}

#endif

