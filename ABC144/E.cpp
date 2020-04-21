#include <iostream>
#include <algorithm>

int main()
{
    const long long MAX_N = 200000;
    long long n, k;
    std::cin >> n >> k;
    long long *a = new long long[n];
    long long *f = new long long[n];

    for (long long i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (long long i = 0; i < n; ++i)
    {
        std::cin >> f[i];
    }

    std::sort(a, a + n);
    std::sort(f, f + n, std::greater<long long>());
    long long *af = new long long[n];
    long long maxAf = 0;
    for (long long i = 0; i < n; ++i)
    {
        af[i] = a[i] * f[i];
        maxAf = af[i] > maxAf ? af[i] : maxAf;
    }

    long long l = 0;
    long long r = maxAf;
    long long med;
    long long ans = -1;
    while (r - l >= 1)
    {
        med = (l + r) / 2;
        long long kc = k;
        for (long long j = 0; j < n; ++j)
        {
            if (af[j] > med)
            {
                kc -= (af[j] - med + f[j] - 1) / f[j];
            }
        }
        if (kc < 0)
        {
            l = med + 1;
            if (ans < med)
            {
                ans = med;
            }
        }
        else
        {
            r = med;
        }
    }

    std::cout << ans + 1;

    return 0;
}