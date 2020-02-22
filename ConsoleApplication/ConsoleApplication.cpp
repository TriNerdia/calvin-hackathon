// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main(int argc, char *argv[])
{

    cout << "\nthere are " << argc << " arguments \n" << endl;

    for (int count{ 0 }; count < argc; ++count)
    {
        cout << count << " " << argv[count] << '\n';
    }

    ifstream config(argv[1]);

    if (config.is_open())
   {
        string text;
        while (getline(config, text))
        {

            if (text == "Yes")
            {
                cout << "the text says yes\n";
            }

            cout << text << endl;

        }
        
        cout << "\nconfig is open\n";
   }
    return 0;
}
