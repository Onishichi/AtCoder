#include <iostream>
#include <algorithm>
#include <string.h>

int main()
{
    int m, n;
    std::cin >> n >> m;

    struct PS
    {
        int p;
        char s[3];
    };

    PS *ps = new PS[m];
    for (int i = 0; i < m; ++i)
    {
        std::cin >> ps[i].p >> ps[i].s;
    }

    bool *ac = new bool[n];
    int *penalty = new int[n];
    for (int i = 0; i < n; ++i)
    {
        ac[i] = false;
        penalty[i] = 0;
    }
    for (int i = m - 1; i >= 0; --i)
    {
        if (strcmp(ps[i].s, "WA") == 0)
        {
            ++penalty[ps[i].p - 1];
        }
        else
        {
            penalty[ps[i].p - 1] = 0;
            ac[ps[i].p - 1] = true;
        }
    }

    int a1 = 0;
    int a2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ac[i])
        {
            ++a1;
            a2 += penalty[i];
        }
    }

    std::cout << a1 << " " << a2;

    return 0;
}