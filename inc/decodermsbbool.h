#ifndef PCARS_DECODER_MSBBOOL_H_
#define PCARS_DECODER_MSBBOOL_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderMSBBool
	/// \brief Decode MS bool from byte
	class DecoderMSBBool : public Decoder {
	public:
		/// Constructor
		DecoderMSBBool();
		/// Destructor
		virtual ~DecoderMSBBool();

		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		void decode(const PCars_Data &, Position &) override;

		/// \brief Get most Significant boolean
		///
		///
		/// \return value
		/// \throw nothing

		bool msb_bool() const;

	private:
		bool num_;
	};

}

#endif

