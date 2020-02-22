#ifndef _INI_CONFIG_
#define _INI_CONFIG_

#include <string>

class INIConfig
{
public:
	INIConfig(char* argv[]);
	std::string iniValue(char* argv[]);
	INIConfig(char*) {}
};

#endif // !_INI_CONFIG_