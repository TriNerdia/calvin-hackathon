#include "INIConfig.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

// Constructor
INIConfig::INIConfig(std::string filename)
{
    this->configData = new std::map<std::string, std::map<std::string, std::string>>();
}

// Destructor
INIConfig::~INIConfig()
{
    delete this->configData;
}

std::list<std::string> INIConfig::getVariables(std::string section)
{
    return std::list<std::string>();
}

std::list<std::string> INIConfig::getSections()
{
    return std::list<std::string>();
}

std::string INIConfig::getValue(std::string section, std::string variable)
{
    return std::string();
}

std::string INIConfig::iniValue(char* argv[])
{
    std::ifstream config(argv[1]);
    std::cout << "iniValue test text";
    if (config.is_open())
    {
        int valuePos;
        std::string text;
        std::string value;
        while (getline(config, text))
        {
            text.erase(std::remove_if(text.begin(), text.end(), isspace), text.end());

            if (text[0] == '[' || text.empty() || text[0] == '#')
                continue;

            valuePos = text.find("=");
            value = text.substr(valuePos + 1);

            std::cout << value << std::endl;

        }

        std::cout << "\nconfig is open\n";
    }

    return "\nreturned\n";

}

void INIConfig::parseConfig(std::string filename)
{
    std::string line, key;
    std::map<std::string, std::string> variables;

    std::ifstream file(filename);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if (line[0] == '[') {
                this->configData->insert()
            }
        }
    }
}

