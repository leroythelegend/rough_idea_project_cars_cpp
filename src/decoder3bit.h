#ifndef PCARS_DECODER_3BIT_H_
#define PCARS_DECODER_3BIT_H_

#include "decodercomposite.h"

#include "decoderls3bits.h"

namespace pcars {

	///
	/// Decode 3 bits from byte
	///

	class Decoder3bit: public DecoderComposite {
	public:

		Decoder3bit();
		virtual ~Decoder3bit() noexcept {}

		///	Decodes PCars Data at position in Data
		void decode(const PCars_Data &, Position &) override;

		/// Get 3 Least significant bits
		unsigned int ls3bits() const;

	private:
		DecoderLS3bits ls3bits_;
	};

}

#endif

