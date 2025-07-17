#include "ScopedTimer.h"
#include "../source/Logging.h"

#include <format>

namespace LoggingAD {

	ScopedTimer::ScopedTimer(const std::string& name, LogLevel level)
		: m_Name(name), m_Level(level), m_StartTime(std::chrono::high_resolution_clock::now())
	{}

	ScopedTimer::~ScopedTimer() {
		Logging::GetInstance().Log(m_Level, std::format("Scoped Timer \"{}\", had length {}", m_Name, std::chrono::high_resolution_clock::now() - m_StartTime));
	}

} // LoggingAD

