#ifndef _INI_CONFIG_
#define _INI_CONFIG_

#include <string>
#include <list>

class INIConfig
{
public:
	INIConfig(std::string filename);
	~INIConfig();

	// Lists
	std::list<std::string> getVariables(std::string section);
	std::list<std::string> getSections();

	// Single Values
	std::string getValue(std::string section, std::string variable);

	std::string iniValue(char* argv[]);
};

#endif // !_INI_CONFIG_