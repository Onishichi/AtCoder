#include <iostream>

int main()
{
    long long h, w;
    std::cin >> h >> w;
    if (h == 1 || w == 1)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    long long oddH = (h + 1) / 2;
    long long oddW = (w + 1) / 2;
    long long evenH = h / 2;
    long long evenW = w / 2;

    long long ans = oddH * oddW + evenH * evenW;

    std::cout << ans << std::endl;

    return 0;
}