
#include <iostream>

#include <LoggingAD.h>
#include <ScopedTimer.h>

int main() {

	LoggingAD::ScopedTimer mainScopeTimer{ "Main" };

	LoggingAD::LoggingConfig config = {
		.OutputLevel = LoggingAD::LogLevel::Trace
	};

	LoggingAD::SetConfig(config);
	

	LoggingAD::Trace("Hello world!");
	std::string world = "Hello world!!";
	LoggingAD::Message("{}", world);
	std::filesystem::path test = "C:/SomethingElse.txt";
	LoggingAD::Info(std::format("{}", test.string()));
	LoggingAD::Warning("{}", test.string());
	LoggingAD::Error("Test!");
}
