#ifndef PCARS_DECODER_3BIT_H_
#define PCARS_DECODER_3BIT_H_

#include "decodercomposite.h"

#include "decoderls3bits.h"

namespace pcars {

	/// \class Decoder3bit
	/// \brief Decode 3 bits from byte

	class Decoder3bit: public DecoderComposite {
	public:
		/// Constructor
		Decoder3bit();
		/// Destructor
		virtual ~Decoder3bit() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get 3 Least significant bits
		///
		/// \return value
		/// \throw nothing

		unsigned int ls3bits() const;

	private:
		DecoderLS3bits ls3bits_;
	};

}

#endif

