
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
	LoggingAD::Trace("Test!");
	int t1 = 1;
	int t2 = 2;
	int& id = t1;
	int& type = t2;
	LoggingAD::Message("[OORenderer::ShaderProgram::Linking] Attaching shader of type: {} with ID: {}", type, id);

}
