#pragma once

#include "../inc/decodercomposite.h"

#include "../inc/decoderms3bits.h"
#include "../inc/decoderls3bits.h"

namespace pcars
{

	///
	/// Decode 6 bits of the byte in 3 seperate bits
	///    0b01110000 and 0b00000111
	///

	class Decoder3bit3bit : public DecoderComposite
	{
	public:
		Decoder3bit3bit();
		virtual ~Decoder3bit3bit() noexcept {}

		///	Decodes PCars Data at position in Data
		void decode(const PCars_Data &, Position &) override;

		/// Get 3 Most significant bits 0b01110000
		unsigned int ms3bits() const;
		/// Get 3 Least significant bits 0b00000111
		unsigned int ls3bits() const;

	private:
		DecoderMS3bits ms3bits_;
		DecoderLS3bits ls3bits_;
	};

}

