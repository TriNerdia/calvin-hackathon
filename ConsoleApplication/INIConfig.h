#ifndef _INI_CONFIG_
#define _INI_CONFIG_

#include <string>
#include <list>
#include <map>

class INIConfig
{
public:

	static std::list<std::string> getSections(std::string);
	static std::map<std::string, std::string> getSectionVars(std::string, std::string);

private:
	INIConfig() {}
};

#endif // !_INI_CONFIG_