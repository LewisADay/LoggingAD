
#pragma once

#include "../source/Logging.h"
#include "../source/LoggingConfig.h"
#include "../source/LogLevel.h"

namespace LoggingAD {

	void SetConfig(const LoggingConfig& config = {}) {
		Logging::GetInstance().SetConfig(config);
	}

	void Log(LogLevel level, const std::string& message) {
		Logging::GetInstance().Log(level, message);
	}

	template<class... Args>
	void Log(LogLevel level, const std::format_string<Args...> format, Args&&... args) {
		Log(level, std::format(format, args...));
	}

	template<class... Args>
	void Trace(const std::format_string<Args...> format, Args&&... args) {
		Log(LogLevel::Trace, format, args...);
	}

	void Trace(const std::string& message) {
		Log(LogLevel::Trace, message);
	}

	template<class... Args>
	void Message(const std::format_string<Args...> format, Args&&... args) {
		Log(LogLevel::Message, format, args...);
	}

	void Message(const std::string& message) {
		Log(LogLevel::Message, message);
	}

	template<class... Args>
	void Info(const std::format_string<Args...> format, Args&&... args) {
		Log(LogLevel::Info, format, args...);
	}

	void Info(const std::string& message) {
		Log(LogLevel::Info, message);
	}

	template<class... Args>
	void Warning(const std::format_string<Args...> format, Args&&... args) {
		Log(LogLevel::Warning, format, args...);
	}

	void Warning(const std::string& message) {
		Log(LogLevel::Warning, message);
	}

	template<class... Args>
	void Error(const std::format_string<Args...> format, Args&&... args) {
		Log(LogLevel::Error, format, args...);
	}

	void Error(const std::string& message) {
		Log(LogLevel::Error, message);
	}

} // LoggingAD
