#include <iostream>

int main()
{
    char s[4];
    std::cin >> s;
    if ((s[0] == 'A' && s[1] == 'A' && s[2] == 'A') || (s[0] == 'B' && s[1] == 'B' && s[2] == 'B'))
    {
        std::cout << "No";
    }
    else
    {
        std::cout << "Yes";
    }
    return 0;
}