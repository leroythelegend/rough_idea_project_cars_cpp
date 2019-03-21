#ifndef PCARS_DECODER_2BIT_3BIT_H_
#define PCARS_DECODER_2BIT_3BIT_H_

#include "decodercomposite.h"

#include "decoderms2bits.h"
#include "decoderls3bits.h"

namespace pcars {

	///
	/// Decode 2 bits and 3 bits from byte
	///

	class Decoder2bit3bit: public DecoderComposite {
	public:

		Decoder2bit3bit();
		virtual ~Decoder2bit3bit() noexcept {}

		///	Decodes PCars Data at position in Data
		void decode(const PCars_Data&, Position&) override;
	
		///	Get the value of the 2 MSB
		unsigned int ms2bits() const;
		///	Get the value of the 3 LSB
		unsigned int ls3bits() const;

	private:
		DecoderMS2bits ms2bits_;
		DecoderLS3bits ls3bits_;
	};

}

#endif

