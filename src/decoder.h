#ifndef PCARS_DECODER_H_
#define PCARS_DECODER_H_

#include "consts.h"

namespace pcars {

	/// \class Decoder
	/// \brief Abstract Decoder
	///
	///		Decodes Project Cars Data

	class Decoder {
	public:
		virtual ~Decoder() {}

		/// \brief decode data at position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		virtual void decode(const PCars_Data &, Position &) = 0;
	};

}

#endif

