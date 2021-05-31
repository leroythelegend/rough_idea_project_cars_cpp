#ifndef PCARS_DECODER_S16_H_
#define PCARS_DECODER_S16_H_

#include "../inc/decoder.h"

#include <cstdint>

namespace pcars {

	/// \class DecoderS16
	/// \brief Decode signed short

	class DecoderS16: public Decoder {
	public:
		/// Constructor
		DecoderS16();
		/// Destructor
		virtual ~DecoderS16();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;
		
		/// \brief Get signed int
		///
		///
		/// \return value
		/// \throw nothing

		int s16() const;

	private:
		int16_t num_;
	};

}

#endif
