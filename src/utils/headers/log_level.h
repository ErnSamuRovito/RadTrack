#pragma once

#include <iostream>

namespace RadTrack
{
namespace Types
{

// Enum per i livelli di log
enum class LogLevelTest
{
    DEBUG = 0,   // Dettagli per il debug
    INFO,        // Informazioni generali
    WARNING,     // Avvisi
    ERROR,       // Errori
    FATAL,       // Errori critici
    DISABLED     // Log disabilitato
};

// Operatore di output per il LogLevelTest
std::ostream &operator<<(std::ostream &os, const LogLevelTest level);

} // namespace Types
} // namespace RadTrack
