#ifndef PCARS_DECODER_S8_H_
#define PCARS_DECODER_S8_H_

#include "decoder.h"

#include <cstdint>

namespace pcars {

	/// \class DecoderS8
	/// \brief Decode signed 8

	class DecoderS8 : public Decoder {
	public:
		/// Constructor
		DecoderS8();
		/// Destructor
		virtual ~DecoderS8();

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

		int s8() const;

	private:
		int8_t num_;
	};

}

#endif
