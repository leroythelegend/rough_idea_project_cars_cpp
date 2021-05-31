#ifndef PCARS_DECODER_3BIT_H_
#define PCARS_DECODER_3BIT_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoderls3bits.h"

namespace pcars {

	///
	/// Decode Just the LSB 3 bits from byte and move on
	/// i.e. we increment the position where DecoderLSB3bits
	/// does not increment position.
	///

	class Decoder3bit: public DecoderComposite {
	public:

		Decoder3bit();
		virtual ~Decoder3bit() noexcept = default;

		void decode(const PCars_Data &, Position &) override;

		/// Get 3 Least significant bits (00000XXX)
		unsigned int ls3bits() const;

	private:
		DecoderLS3bits ls3bits_;
	};

}

#endif

