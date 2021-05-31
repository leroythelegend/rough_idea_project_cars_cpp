#ifndef PCARS_DECODER_4BIT_4BIT_H_
#define PCARS_DECODER_4BIT_4BIT_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoderms4bits.h"
#include "../inc/decoderls4bits.h"

namespace pcars {

    /// \class Decoder4bit4bit
	/// \brief Decode LSB 4bits and MSB 4bits from byte

	class Decoder4bit4bit : public DecoderComposite {
	public:
		/// Constructor
		Decoder4bit4bit();
		/// Destructor
		virtual ~Decoder4bit4bit() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get Most Significant 4bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ms4bits() const;

		/// \brief Get Least Significant 4bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ls4bits() const;

	private:
		DecoderMS4bits ms4bits_;
		DecoderLS4bits ls4bits_;
	};

}

#endif

