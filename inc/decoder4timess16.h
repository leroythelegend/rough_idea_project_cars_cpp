#ifndef PCARS_DECODER_4TIMES_S16_H_
#define PCARS_DECODER_4TIMES_S16_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoders16.h"

namespace pcars {

	/// \class Decoder4TimesS16
	/// \brief Decode Short Vector

	class Decoder4TimesS16 : public DecoderComposite {
	public:
		/// Constructors
		Decoder4TimesS16();
		/// Destructors
		virtual ~Decoder4TimesS16() {}

		/// \brief Get vector of short
		///
		///
		/// \return value
		/// \throw nothing

		Vector_Int times4_s16() const;

	private:
		DecoderS16 first_;
		DecoderS16 second_;
		DecoderS16 third_;
		DecoderS16 forth_;

	};

}

#endif

