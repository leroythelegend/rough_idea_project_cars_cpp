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

        void encode(const TelemetryData::Ptr &);

    private:
        std::ofstream file_;

        CSVEncoder(const CSVEncoder &) = delete;
        const CSVEncoder &operator=(const CSVEncoder &) = delete;
    };

} // namespace pcars
