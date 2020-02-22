#include <iostream>
#include <string>
#include <map>
#include <list>

#include "AppCheckTests.h"
#include "INIConfig.h"

int main(int argc, char *argv[])
{
	std::string filename, test;
	if(argc >= 3) {
		// first arg is config file
		// second arg is the test to run
		filename = argv[1];
		test = argv[2];
	}
	else {
		std::cout << "ConsoleApplication.exe <config> <test>" << std::endl;
		return 1;
	}

	std::list<std::string> sections = INIConfig::getSections(filename);
	std::map<std::string, std::string> general = INIConfig::getSectionVars(filename, "general");
	std::map<std::string, std::string> variables = INIConfig::getSectionVars(filename, test);

	std::cout << "Test Results" << std::endl;
	bool result = false;
	if (test == "testport") {
		result = AppCheckTests::check_port(general["hostname"], atoi(variables["port"].c_str()));
		std::cout << "============" << std::endl;
		std::cout << "Port Check: " << (result ? "True" : "False") << std::endl;
	}
	else if (test == "testweb") {
		std::string url = variables["proto"] + "://" + general["hostname"] + ":" + variables["port"] + variables["url"];
		result = AppCheckTests::http_get_string(url, variables["search"]);
		std::cout << "============" << std::endl;
		std::cout << "Web Check: " << (result ? "True" : "False") << std::endl;
	}
}
