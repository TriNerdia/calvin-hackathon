#ifndef _INI_CONFIG_
#define _INI_CONFIG_

#include <string>
#include <list>
#include <map>

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

private:
	std::map<std::string, std::map<std::string, std::string>>* configData;
	void parseConfig(std::string filanem);

};

#endif // !_INI_CONFIG_