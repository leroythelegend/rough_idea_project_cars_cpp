#pragma once

#include "../inc/decodercomposite.h"

#include "../inc/decoderls3bits.h"
#include "../inc/decoderbottom2bits.h"
#include "../inc/decodertop2bits.h"
#include "../inc/decodermsbbool.h"

namespace pcars
{

	///
	///	Decodes sequence of bits in byte
	///

	class Decoder1bit2bit2bit3bit : public DecoderComposite
	{
	public:
		Decoder1bit2bit2bit3bit();
		virtual ~Decoder1bit2bit2bit3bit() noexcept = default;

		void decode(const PCars_Data &, Position &) override;

		///	Get the value of the 3 LSBits (00000XXX)
		unsigned int lsb_3bit() const;
		///	Get the value of next 2 bits (000XX000)
		unsigned int bottom_2bit() const;
		///	Get the value of next 2 bits (0XX00000)
		unsigned int top_2bit() const;
		///	Get the value of MSB (X0000000)
		bool msb_1bit() const;

	private:
		DecoderLS3bits lsb3bit_;
		DecoderBottom2bits b2bit_;
		DecoderTop2bits t2bit_;
		DecoderMSBBool msb1bit_;
	};

}

