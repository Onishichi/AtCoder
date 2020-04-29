#include <bits/stdc++.h>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    while (1)
    {
        c -= b;
        if (c <= 0)
        {
            std::cout << "Yes" << std::endl;
            break;
        }
        a -= d;
        if (a <= 0)
        {
            std::cout << "No" << std::endl;
            break;
        }
    }
    return 0;
}