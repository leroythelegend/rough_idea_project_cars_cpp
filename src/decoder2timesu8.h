#ifndef PCARS_DECODER_2TIMESU8_H_
#define PCARS_DECODER_2TIMESU8_H_

#include "decodercomposite.h"

#include "decoderu8.h"

namespace pcars {

	/// \class Decoder2TimesU8
	/// \brief Decode 2 times unsigned int
	///
	///		Decode 2 times unsigned int
	class Decoder2TimesU8: public DecoderComposite {
	public:
		/// Constructor
		Decoder2TimesU8();
		/// Destructor
		virtual ~Decoder2TimesU8();

		/// \brief Get vector of unsigned int
		///
		///		Get vector size 2 of unsigned int

		Vector_UInt times2_U8() const;

	private:
		DecoderU8 first_;
		DecoderU8 second_;
	};

}

#endif

