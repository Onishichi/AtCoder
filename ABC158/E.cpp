#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n, p;
    std::string s;
    std::cin >> n >> p >> s;

    long long ans = 0;
    if (p == 2)
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')
            {
                ans += i + 1;
            }
        }
    }
    else if (p == 5)
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0' || s[i] == '5')
            {
                ans += i + 1;
            }
        }
    }
    else
    {
        int rem10 = 10 % p;
        int rem10pow = 1;
        std::vector<int> rem;
        rem.resize(n + 1);
        rem[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            rem[i] = (rem[i + 1] + ((s[i] - '0') % p) * rem10pow) % p;
            rem10pow = (rem10pow * rem10) % p;
        }

        std::vector<long long> count;
        count.resize(p);
        std::fill(count.begin(), count.end(), 0);
        for (int i = 0; i <= n; ++i)
        {
            ++count[rem[i]];
        }

        for (int i = 0; i < p; ++i)
        {
            ans += count[i] * (count[i] - 1);
        }
        ans /= 2;
    }
    std::cout << ans << std::endl;

    return 0;
}