#include "INIConfig.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

std::map<std::string, std::string> INIConfig::getSectionVars(std::string filename, std::string section)
{
    std::string line;
    std::map<std::string, std::string> variables;

    // this flag is used to indicate when the loop should
    // store variables in the map.
    bool look_for_variables = false;

    std::ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.empty() || (line.length() > 0 && line[0] == '#')) {
                continue;
            }

            if (line[0] == '[') {
                look_for_variables = false;

                // Cleaning up the string
                line.erase(std::remove_if(line.begin(), line.end(), ispunct), line.end());

                if (line == section) {
                    look_for_variables = true;
                    continue;
                }
            }

            if (look_for_variables) {
                line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
                int delimiter = line.find("=");
                std::string name = line.substr(0, delimiter);
                std::string value = line.substr(delimiter + 1);
                variables[name] = value;
            }
        }

        file.close();
    }

    return variables;
}

std::list<std::string> INIConfig::getSections(std::string filename)
{
    std::string line;
    std::list<std::string> sections;

    std::ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.empty() || (line.length() > 0 && line[0] == '#')) {
                continue;
            }

            if (line[0] == '[') {
                //look_for_variables = false;

                // Cleaning up the string
                line.erase(std::remove_if(line.begin(), line.end(), ispunct), line.end());

                sections.push_back(line);

                    
            }
        }

        file.close();
    }



    return sections;
}


