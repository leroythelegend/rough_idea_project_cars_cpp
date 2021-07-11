#pragma once

#include <stdexcept>

static void assert(bool b)
{
    if (!b)
    {
        throw std::runtime_error("false");
    }
}