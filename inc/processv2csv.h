#ifndef PCARS_MYPROCESS_H_
#define PCARS_MYPROCESS_H_

#include <memory>
#include <vector>

#include "../inc/process.h"

namespace pcars {

	/// \class MyProcess
	/// \brief My Process

	class ProcessV2CSV : public Process {
	public:

		/// Destructor
		ProcessV2CSV() = default;
		virtual ~ProcessV2CSV() = default;

		/// \brief process playing packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void playing(PacketPtr &) override;

		/// \brief process menu packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void menu(PacketPtr &) override;

	private:
		int packets_;

		ProcessV2CSV(const ProcessV2CSV &) = delete;
		const ProcessV2CSV &operator =(const ProcessV2CSV &) = delete; 
	};


}

#endif
