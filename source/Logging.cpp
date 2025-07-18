
#include "Logging.h"
#include <chrono>
#include <array>
#include <cstring>

namespace LoggingAD {

	std::string_view Logging::LogLevelToStringView(LogLevel level) {

		const std::array<std::string_view, 5> mapping {
			"Trace",
			"Message",
			"Info",
			"Warning",
			"Error"
		};

		return mapping[static_cast<int>(level)];
	}

	void Logging::Log(const LogLevel level, const std::string& message) {
		if (level >= m_Config.OutputLevel) {

			if (m_Config.LogToFile) {
				m_FileStream.open(m_Config.LogFilePath, std::ios::out | std::ios::app);
				if (!m_FileStream.is_open()) {
					static_assert("[LoggingAD::Logging] Failed to log to file, could not open file.");
				}
				m_Config.Stream = &m_FileStream;
			}

			if (m_Config.LogTime) {
				std::time_t now = std::time(nullptr);
				tm* dateTime = std::localtime(&now);
				std::format_to(
					std::ostream_iterator<char>(*m_Config.Stream), // Send straight to stream, no need for temp local string
					"[{:0>4}-{:0>2}-{:0>2} {:0>2}:{:0>2}:{:0>2}] ",
					dateTime->tm_year + 1900, dateTime->tm_mon + 1, dateTime->tm_mday,
					dateTime->tm_hour, dateTime->tm_min, dateTime->tm_sec
				);
			}

			if (m_Config.PrependLogLevel) {
				std::format_to(
					std::ostream_iterator<char>(*m_Config.Stream), // Send straight to stream, no need for temp local string
					"[{: <7}] ",
					LogLevelToStringView(level)
				);
			}

			*m_Config.Stream << message << std::endl;;

			if (m_Config.LogToFile) {
				m_FileStream.close();
			}
		}
	}

	void Logging::SetConfig(const LoggingConfig& config) {
		m_Config = config;

		if (m_Config.LogToFile && m_Config.LogFilePath.empty()) {
			Log(LogLevel::Error, "[LoggingAD::Logging] Logging to file enabled, but no file specified. Please verify your LoggingConfiguration.");
			static_assert("[LoggingAD::Logging] Logging to file enabled, but no file specified. Please verify your LoggingConfiguration.");
		}
	}

	Logging& Logging::GetInstance() {
		static Logging instance;
		return instance;
	}

} // LoggingAD


