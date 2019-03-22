#ifndef PCARS_DECODER_1BIT_2BIT_2BIT_3BIT_H_
#define PCARS_DECODER_1BIT_2BIT_2BIT_3BIT_H_

#include "decodercomposite.h"

#include "decoderls3bits.h"
#include "decoderbottom2bits.h"
#include "decodertop2bits.h"
#include "decodermsbbool.h"

namespace pcars {

	///
	///	Decodes sequence of bits in byte
	///

	class Decoder1bit2bit2bit3bit: public DecoderComposite {
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

#endif

