#pragma once

#include <ostream>

namespace RadTrack
{

namespace Types
{

enum class LogLevel
{
    DEBUG = 0,
    INFO,
    WARNING,
    ERROR,
    OUTPUT,
    DISABLED
};

std::ostream &operator<<(std::ostream &os, const LogLevel level);

}

}
