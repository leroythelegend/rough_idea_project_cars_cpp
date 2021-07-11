#pragma once

#include <stdexcept>

static void pcars_assert(bool b)
{
    if (!b)
    {
        throw std::runtime_error("false");
    }
}