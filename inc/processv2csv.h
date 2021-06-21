#pragma once

#include <memory>
#include <vector>
#include <string>

#include "process.h"
#include "processv2csvimpl.h"

namespace pcars
{

	/// \class ProcessV2CSV
	/// \brief Process v2 telemetry into a csv file

	class ProcessV2CSV : public Process
	{
	public:
		ProcessV2CSV(const ProcessV2CSVImpl::Ptr &);
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

		void reset(PacketPtr &) override;

	private:
		ProcessV2CSVImpl::Ptr impl_;

		ProcessV2CSV(const ProcessV2CSV &) = delete;
		const ProcessV2CSV &operator=(const ProcessV2CSV &) = delete;
	};

}
