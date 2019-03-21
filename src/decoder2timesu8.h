#ifndef PCARS_DECODER_2TIMESU8_H_
#define PCARS_DECODER_2TIMESU8_H_

#include "decodercomposite.h"

#include "decoderu8.h"

namespace pcars {

	///
	///	Decode 2 times unsigned int
	///

	class Decoder2TimesU8: public DecoderComposite {
	public:

		Decoder2TimesU8();
		virtual ~Decoder2TimesU8() noexcept {}

		///	Get vector size 2 of unsigned int
		Vector_UInt times2_U8() const;

	private:
		DecoderU8 first_;
		DecoderU8 second_;
	};

}

#endif

