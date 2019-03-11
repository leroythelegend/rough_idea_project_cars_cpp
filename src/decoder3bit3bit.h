#ifndef PCARS_DECODER_3BIT_3BIT_H_
#define PCARS_DECODER_3BIT_3BIT_H_

#include "decodercomposite.h"

#include "decoderms3bits.h"
#include "decoderls3bits.h"

namespace pcars {

	/// \class Decoder3bit3bit
	/// \brief Decode 6 bits of the byte in 3 seperate bits

	class Decoder3bit3bit : public DecoderComposite {
	public:
		/// \Constructor
		Decoder3bit3bit();
		/// \Destructor
		virtual ~Decoder3bit3bit() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get 3 Most significant bits
		///
		/// \return value
		/// \throw nothing

		unsigned int ms3bits() const;

		/// \brief Get 3 Least significant bits
		///
		/// \return value
		/// \throw nothing

		unsigned int ls3bits() const;

	private:
		DecoderMS3bits ms3bits_;
		DecoderLS3bits ls3bits_;
	};

}

#endif

