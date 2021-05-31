#ifndef PCARS_3TIMES_S16_H_
#define PCARS_3TIMES_S16_H_

#include "../inc/decodercomposite.h"

#include "../inc/decoders16.h"

namespace pcars {

	/// \class Decoder3TimesS16
	/// \brief Decode 3 times signed short

	class Decoder3TimesS16 : public DecoderComposite {
	public:
		/// Constructor
		Decoder3TimesS16();
		/// Destructor
		virtual ~Decoder3TimesS16() {}

		/// \brief Get Vector of shorts
		///
		///
		/// \return value
		/// \throw nothing

		Vector_Int times3_s16() const;

	private:
		DecoderS16 first_;
		DecoderS16 second_;
		DecoderS16 third_;
	};

}

#endif

