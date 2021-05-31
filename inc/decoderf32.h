#ifndef PCARS_DECODER_F32_H_
#define PCARS_DECODER_F32_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderF32
	class DecoderF32 : public Decoder {
	public:
		/// Constructor
		DecoderF32();
		/// Destructor
		virtual ~DecoderF32() {}

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get value of Float
		///
		///
		/// \return value
		/// \throw nothing

		float f32() const;

	private:
		float num_;
	};

} /* namespace pcars */

#endif /* PCARS_DecoderF32_H_ */
