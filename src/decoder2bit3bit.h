#ifndef PCARS_DECODER_2BIT_3BIT_H_
#define PCARS_DECODER_2BIT_3BIT_H_

#include "decodercomposite.h"

#include "decoderms2bits.h"
#include "decoderls3bits.h"

namespace pcars {

	/// \class Decoder2bit3bit
	/// \brief Decode 2bits and 3bits from byte
	///
	///		Decode 2 bits and 3 bits from byte

	class Decoder2bit3bit: public DecoderComposite {
	public:
		/// Constructor
		Decoder2bit3bit();
		/// Destructor
		virtual ~Decoder2bit3bit() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data&, Position&) override;

		/// \brief 2 Most Significant bits
		///
		///		Get the value of the 2 MSB
		///
		/// \return value
		/// \throw nothing
	
		unsigned int ms2bits() const;

		/// \brief 3 Least Significant bits
		///
		///		Get the value of the 3 LSB
		///
		/// \return value
		/// \throw nothing

		unsigned int ls3bits() const;

	private:
		DecoderMS2bits ms2bits_;
		DecoderLS3bits ls3bits_;
	};

}

#endif

