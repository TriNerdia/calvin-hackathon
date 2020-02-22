// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

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
            text.erase(remove_if(text.begin(), text.end(), isspace), text.end());

            if (text[0] == '#' || text.empty())
                continue;

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
