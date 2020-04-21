#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int xamin, xbmin, xamax, xbmax;
    xamin = (a * 100 + 7) / 8;
    xbmin = (b * 100 + 9) / 10;
    xamax = ((a + 1) * 100 + 7) / 8 - 1;
    xbmax = ((b + 1) * 100 + 9) / 10 - 1;
    int ans;
    if (xamin <= xbmin && xbmin <= xamax)
    {
        ans = xbmin;
    }
    else if (xbmin <= xamin && xamin <= xbmax)
    {
        ans = xamin;
    }
    else
    {
        ans = -1;
    }

    std::cout << ans << std::endl;
    return 0;
}