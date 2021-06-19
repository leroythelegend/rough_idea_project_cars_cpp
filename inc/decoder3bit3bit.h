#ifndef PCARS_DECODER_3BIT_3BIT_H_
#define PCARS_DECODER_3BIT_3BIT_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoderms3bits.h"
#include "../inc/decoderls3bits.h"

namespace pcars
{

	///
	/// Decode 6 bits of the byte in 3 seperate bits
	///

	class Decoder3bit3bit : public DecoderComposite
	{
	public:
		Decoder3bit3bit();
		virtual ~Decoder3bit3bit() noexcept {}

		///	Decodes PCars Data at position in Data
		void decode(const PCars_Data &, Position &) override;

		/// Get 3 Most significant bits
		unsigned int ms3bits() const;
		/// Get 3 Least significant bits
		unsigned int ls3bits() const;

	private:
		DecoderMS3bits ms3bits_;
		DecoderLS3bits ls3bits_;
	};

}

#endif
