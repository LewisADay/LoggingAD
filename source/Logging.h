
#pragma once

#include <memory>
#include <string>
#include <ostream>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <format>

#include "LoggingConfig.h"
#include "LogLevel.h"

namespace LoggingAD {

	class Logging {
	public:
		static Logging& GetInstance();

	public:
		void SetConfig(const LoggingConfig& config = {});
		void Log(const LogLevel level, const std::string& message);

	private:
		Logging() = default;
		std::string_view LogLevelToStringView(LogLevel level);

	private:
		LoggingConfig m_Config = {};
		std::ofstream m_FileStream{};

	};

} // LoggingAD
