// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;



int main(int argc, char *argv[])
{

    cout << "there are " << argc << " arguments ";
    for (int count{ 0 }; count < argc; ++count)
    {
        cout << count << " " << argv[count] << '\n';
    }

    return 0;
}
