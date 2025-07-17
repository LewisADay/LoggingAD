
#pragma once
#include "../source/LogLevel.h"

#include <chrono>
#include <string>

namespace LoggingAD {

	class ScopedTimer {

	public:
		ScopedTimer(const std::string& name, LogLevel level = LogLevel::Info);
		~ScopedTimer();

	private:
		std::string m_Name;
		LogLevel m_Level;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
	};

} // LoggingAD
