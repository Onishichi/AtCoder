#include <iostream>

int main()
{
    long long a, b, c;
    std::cin >> a >> b >> c;
    long long cab = c - a - b;
    if (4 * a * b >= cab * cab || cab < 0)
    {
        std::cout << "No" << std::endl;
    }
    else
    {
        std::cout << "Yes" << std::endl;
    }
    return 0;
}