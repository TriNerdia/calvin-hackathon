// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include "AppCheckTests.h"
#include "INIConfig.h"
using namespace std;



int main(int argc, char *argv[])
{
	std::map<std::string, std::string> data = INIConfig::parseConfig("example-config.ini", "general");
	//for (auto i : data) {
	//	std::cout << i.first << std::endl;
	//	std::cout << i.second << std::endl;
	//}
}
