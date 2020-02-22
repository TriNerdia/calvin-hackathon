// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "AppCheckTests.h"
#include "INIConfig.h"
using namespace std;



int main(int argc, char *argv[])
{
    AppCheckTests::http_get_string("http://hackathon.demonpig.net", "hello world");
    
   //INIConfig config = INIConfigManager::get_tests(argv[1]);
   

   INIConfig* iniValue = new INIConfig(argv[1]);
   // config->get("port_test")
    
   cout << iniValue;
        
        //cout << "\nthere are " << argc << " arguments \n" << endl;

    //for (int count{ 0 }; count < argc; ++count)
    //{
    //    cout << count << " " << argv[count] << '\n';
   // }

   
    return 0;
}
/*
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

void print(list<string> const& list)
{
    for (auto const& i: list) {
        cout << i << "\n";
    }
}

int main(int argc, char* argv[])
{
    list <string> sections;
    map<string, string> variables;

    ifstream cFile(argv[1]);
    if (cFile.is_open())
    {
        string line;
        while (getline(cFile, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if (line[0] == '[')
            {
                string name = line;
                sections.push_front(name);
            }

            else if (line[0] == '#' || line.empty())
                continue;
            int delimiterPos = line.find("=");
            string name = line.substr(0, delimiterPos);
            string value = line.substr(delimiterPos + 1);
           // variables.insert(name, value);

            //cout << name << " = " << value << '\n';



        }

    }
    else {
        cerr << "Couldn't open config file for reading.\n";
    }
    print(sections);
}

*/