#ifndef PCARS_MS6BITS_H_
#define PCARS_MS6BITS_H_

#include "decoder.h"

namespace pcars {

	/// \class DecoderMS6bits
	/// \brief Decode MS 6 bits from byte

	class DecoderMS6bits : public Decoder {
	public:
		/// Constructor
		DecoderMS6bits();
		/// Destructor
		virtual ~DecoderMS6bits();

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

	private:
		int num_;
	};

} /* namespace pcars */

#endif /* PCARS_MS6BITS_H_ */
