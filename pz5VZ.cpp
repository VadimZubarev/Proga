#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    setlocale(LC_ALL, "Russian");
    ifstream ifout;
    ifout.open("file.txt");
    string line;
    vector <string> filetext;
    while (!ifout.eof())
    {
        getline(ifout, line);
        filetext.push_back(line);
    }

    vector<string> firstsearch;
    vector<string> secondsearch;
    vector<string> thirdsearch;

    int size;
    char letter;
    int console;
    int search = 0;

    while (true)
    {
        cout << "1. начинается с ...\t 2. длина \t 3. заканчивается на ...\t 4. сброс\t 5. выход\t6. текст в файле\n" ;
        cin >> console;
        switch (console)
        {
        case 1:
            cout << "буква: ";
            cin >> letter;
            if (search == 0)
            {
                copy_if(filetext.begin(), filetext.end(), back_inserter(firstsearch), [=](string str)
                    {
                        return str[0] == letter;
                    });
                for (auto i : firstsearch)
                {
                    cout << i << endl;
                }
            }
            else if (search == 1)
            {
                copy_if(firstsearch.begin(), firstsearch.end(), back_inserter(secondsearch), [=](string str)
                    {
                        return str[0] == letter;
                    });
                for (auto i : secondsearch)
                {
                    cout << i << endl;
                }
            }
            else if (search == 2)
            {
                 copy_if(secondsearch.begin(), secondsearch.end(), back_inserter(thirdsearch), [=](string str)
                    {
                        return str[0] == letter;
                    });
                 for (auto i : thirdsearch)
                 {
                     cout << i << endl;
                 }
            }
            search++;
            break;
        case 2:
            cout << "цифра: ";
            cin >> size;
            if (search == 0)
            {
                copy_if(filetext.begin(), filetext.end(), back_inserter(firstsearch), [=](string str)
                    {
                        return str.length() >= size;
                    });
                for (auto i : firstsearch)
                {
                    cout << i << endl;
                }
            }
            else if (search == 1)
            {
                copy_if(firstsearch.begin(), firstsearch.end(), back_inserter(secondsearch), [=](string str)
                    {
                        return str.length() >= size;
                    });
                for (auto i : secondsearch)
                {
                    cout << i << endl;
                }
            }
            else if (search == 2)
            {
                 copy_if(secondsearch.begin(), secondsearch.end(), back_inserter(thirdsearch), [=](string str)
                    {
                         return str.length() >= size;
                    });
                 for (auto i : thirdsearch)
                 {
                     cout << i << endl;
                 }
            }
            search++;
            break;
        case 3:
            cout << "буква: ";
            cin >> letter;
            if (search == 0)
            {
                copy_if(filetext.begin(), filetext.end(), back_inserter(firstsearch), [=](string str)
                    {
                        if (str.length() > 0)
                            return str[str.length() - 1] == letter;
                    });
                for (auto i : firstsearch)
                {
                    cout << i << endl;
                }
            }
            else if (search == 1)
            {
                copy_if(firstsearch.begin(), firstsearch.end(), back_inserter(secondsearch), [=](string str)
                    {
                        return str[str.length() - 1] == letter;
                    });
                for (auto i : secondsearch)
                {
                    cout << i << endl;
                }
            }
            else if (search == 2)
            {
                copy_if(secondsearch.begin(), secondsearch.end(), back_inserter(thirdsearch), [=](string str)
                    {
                        return str[str.length() - 1] == letter;
                    });
                for (auto i : thirdsearch)
                {
                    cout << i << endl;
                }
            }
            search++;
            break;
        case 4:
            firstsearch.erase(firstsearch.begin());
            secondsearch.erase(secondsearch.begin());
            thirdsearch.erase(thirdsearch.begin());
            search = 0;

        case 5:
            exit(0);

        case 6:
            for (auto i : filetext)
            {
                cout << i << endl;
            }
        }
        if (search == 3)
        {
            firstsearch.erase(firstsearch.begin());
            secondsearch.erase(secondsearch.begin());
            thirdsearch.erase(thirdsearch.begin());
            search = 0;
            cout << "\nавтоматический сброс\n";
        }
    }
}
