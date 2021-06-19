#pragma once

#include <string>
#include <memory>
#include <fstream>

#include "processv2csv.h"

namespace pcars
{
    class CSVEncoder
    {
    public:
        using Filename = std::string;

        CSVEncoder(const Filename &);
        ~CSVEncoder() = default;

        void encode(const std::unique_ptr<pcars::TelemetryData> &);

    private:
        std::ofstream file_;
    };

} // namespace pcars
