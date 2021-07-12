#pragma once

#include "../inc/decodercomposite.h"

#include "../inc/decoderms2bits.h"
#include "../inc/decoderls3bits.h"

namespace pcars
{

	///
	/// Decode 00XX0000 and 00000XXX
	///

	class Decoder2bit3bit : public DecoderComposite
	{
	public:
		Decoder2bit3bit();
		virtual ~Decoder2bit3bit() noexcept = default;

		void decode(const PCars_Data &, Position &) override;

		///	Get the value of 00XX0000
		unsigned int ms2bits() const;
		///	Get the value of 00000XXX
		unsigned int ls3bits() const;

	private:
		DecoderMS2bits ms2bits_;
		DecoderLS3bits ls3bits_;
	};

}

