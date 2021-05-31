#ifndef PCARS_DECODER_COMPOSITE_H_
#define PCARS_DECODER_COMPOSITE_H_

#include "../inc/decoder.h"

namespace pcars {

	/// \class DecoderComposite
	/// \brief Decode each added decoder

	class DecoderComposite : public Decoder {
	public:
		using Vector_Decoder = std::vector<Decoder *>;
		using Type = std::string;

		/// Destructor
		virtual ~DecoderComposite() {}
		
		/// \brief Decode PCars Data at Position
		///
		///		Decodes PCars Data at position in Data
		///
		/// \param PCars_Data: data to be decoded
		/// \param Postion: position in data to be decoded
		/// \return void
		/// \throw nothing

		virtual void decode(const PCars_Data &, Position &);

		/// \brief Add decoder to vector
		///
		///
		/// \param decoder
		/// \return value
		/// \throw nothing

		void add(Decoder *);

	private:
		Vector_Decoder decoders_;
		Vector_Decoder::iterator iter_;
	};

}

#endif

