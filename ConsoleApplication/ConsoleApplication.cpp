#include <iostream>
#include <string>
#include <map>
#include <list>

#include "AppCheckTests.h"
#include "INIConfig.h"

int main(int argc, char *argv[])
{



	std::list<std::string> sections = INIConfig::getSections(argv[1]);

	for (auto i : sections)
	{
		std::cout << i << std::endl;
	}
	

	std::map<std::string, std::string> variables = INIConfig::getSectionVars(argv[1], argv[2]);

	for (auto i : variables)
	{
		std::cout << "\n" << i.first << " " << i.second << std::endl;
	}


}
