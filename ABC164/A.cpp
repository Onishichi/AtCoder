#include <bits/stdc++.h>

int main()
{
    int s, w;
    std::cin >> s >> w;
    if (s > w)
    {
        std::cout << "safe" << std::endl;
    }
    else
    {
        std::cout << "unsafe" << std::endl;
    }
    return 0;
}