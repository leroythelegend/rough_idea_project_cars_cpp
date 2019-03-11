#ifndef PCARS_DECODER_1BIT_2BIT_2BIT_3BIT_H_
#define PCARS_DECODER_1BIT_2BIT_2BIT_3BIT_H_

#include "decodercomposite.h"

#include "decoderls3bits.h"
#include "decoderbottom2bits.h"
#include "decodertop2bits.h"
#include "decodermsbbool.h"

namespace pcars {

	/// \class Decoder1bit2bit2bit3bit
	/// \brief Decode 1bit 2bit 2bit 3bit
	///
	///		Decodes sequence of bits in byte

	class Decoder1bit2bit2bit3bit: public DecoderComposite {
	public:

		/// Constructor
		Decoder1bit2bit2bit3bit();
		/// Destructor
		virtual ~Decoder1bit2bit2bit3bit();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief 3 Least Significant bits
		///
		///		Get the value of the 3 LSBits (00000XXX)
		///
		/// \return value
		/// \throw nothing

		unsigned int lsb_3bit() const;
		
		/// \brief Next 2 bits in byte
		///
		///		Get the value of next 2 bits (000XX000)
		///
		/// \return value
		/// \throw nothing

		unsigned int bottom_2bit() const;

		/// \brief Next 2 bits in byte
		///
		///		Get the value of next 2 bits (0XX00000)
		///
		/// \return value
		/// \throw nothing

		unsigned int top_2bit() const;

		/// \brief Most Significant Bit
		///
		///		Get the value of MSB (X0000000)
		///
		/// \return value
		/// \throw nothing
	
		bool msb_1bit() const;

	private:
		DecoderLS3bits lsb3bit_;
		DecoderBottom2bits b2bit_;
		DecoderTop2bits t2bit_;
		DecoderMSBBool msb1bit_;

	};

}

#endif

