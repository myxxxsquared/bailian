#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    int size;
    std::cin >> size;

    std::map<std::string, int> m;

    for (int i = 0; i < size; ++i)
    {
        std::string str;
        std::cin >> str;
        std::vector<char> paste;
        paste.reserve(7);
        for (char ch : str)
        {
            switch (ch)
            {
            case '0':
                paste.push_back('0');
                break;
            case '1':
                paste.push_back('1');
                break;
            case '2':
            case 'A':
            case 'B':
            case 'C':
                paste.push_back('2');
                break;
            case '3':
            case 'D':
            case 'E':
            case 'F':
                paste.push_back('3');
                break;
            case '4':
            case 'G':
            case 'H':
            case 'I':
                paste.push_back('4');
                break;
            case '5':
            case 'J':
            case 'K':
            case 'L':
                paste.push_back('5');
                break;
            case '6':
            case 'M':
            case 'N':
            case 'O':
                paste.push_back('6');
                break;
            case '7':
            case 'P':
            case 'R':
            case 'S':
                paste.push_back('7');
                break;
            case '8':
            case 'T':
            case 'U':
            case 'V':
                paste.push_back('8');
                break;
            case '9':
            case 'W':
            case 'X':
            case 'Y':
                paste.push_back('9');
                break;
            default:
                break;
            }
        }

        std::string result = std::string(paste.data(), 3) + std::string("-") + std::string(paste.data() + 3, 4);

        std::map<std::string, int>::iterator it = m.find(result);
        if (it == m.end())
        {
            m.insert(std::make_pair(result, 1));
        }
        else
        {
            ++(it->second);
        }
    }

    std::vector<std::pair<std::string, int>> resultvector;
    resultvector.insert(resultvector.end(), m.begin(), m.end());
    std::sort(resultvector.begin(), resultvector.end());

    bool dup = false;

    for (std::pair<std::string, int> &pair : resultvector)
    {
        if (pair.second > 1)
        {
            std::cout << pair.first << " " << pair.second << std::endl;
            dup = true;
        }
    }

    if (!dup)
    {
        std::cout << "No duplicates." << std::endl;
    }
}