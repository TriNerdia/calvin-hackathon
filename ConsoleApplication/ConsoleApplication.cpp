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
        
        cout << "\nthere are " << argc << " arguments \n" << endl;

    for (int count{ 0 }; count < argc; ++count)
    {
        cout << count << " " << argv[count] << '\n';
    }

   
    return 0;
}
