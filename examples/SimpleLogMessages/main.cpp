
#include <iostream>

#include <LoggingAD.h>

int main() {

	LoggingAD::LoggingConfig config = {
		.OutputLevel = LoggingAD::LogLevel::Trace,
		.LogToFile = true,
		.LogFilePath = "temp.txt",
	};

	LoggingAD::Init(config);

	LoggingAD::Trace("Hello world!");
	LoggingAD::Message("Hello world!");
	LoggingAD::Info("Hello world!");
	LoggingAD::Warning("Hello world!");
	LoggingAD::Error("Hello world!");

}
