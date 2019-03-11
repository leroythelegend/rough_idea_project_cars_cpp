#ifndef PCARS_DECODER_6BIT_2BIT_H_
#define PCARS_DECODER_6BIT_2BIT_H_

#include "decodercomposite.h"

#include "decoderms6bits.h"
#include "decoderls2bits.h"

namespace pcars {

	/// \class Decoder6bit2bit
	class Decoder6bit2bit : public DecoderComposite {
	public:
		/// Constructor
		Decoder6bit2bit();
		/// Destructor
		virtual ~Decoder6bit2bit() {}
		
		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get most Significant 6bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ms6bits() const;

		/// \brief Get least Significant 2bits
		///
		///
		/// \return value
		/// \throw nothing

		unsigned int ls2bits() const;

	private:
		DecoderMS6bits ms6bits_;
		DecoderLS2bits ls2bits_;
	};

}

#endif

