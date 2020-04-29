#include <bits/stdc++.h>

const int mod = 1000000007;
struct mod_int
{
    long long x;
    mod_int(long long x = 0) : x((x % mod + mod) % mod) {}
    mod_int operator-() const { return mod_int(-x); }
    mod_int &operator+=(const mod_int a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mod_int &operator-=(const mod_int a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mod_int &operator*=(const mod_int a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mod_int operator+(const mod_int a) const
    {
        mod_int res(*this);
        return res += a;
    }
    mod_int operator-(const mod_int a) const
    {
        mod_int res(*this);
        return res -= a;
    }
    mod_int operator*(const mod_int a) const
    {
        mod_int res(*this);
        return res *= a;
    }
    mod_int pow(long long t) const
    {
        if (!t)
            return 1;
        mod_int a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    mod_int inv() const
    {
        return pow(mod - 2);
    }
    mod_int &operator/=(const mod_int a)
    {
        return (*this) *= a.inv();
    }
    mod_int operator/(const mod_int a) const
    {
        mod_int res(*this);
        return res /= a;
    }
};

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<mod_int> stairSum(n + 1);
    stairSum[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        stairSum[i] = stairSum[i - 1] + i;
    }
    mod_int sum = 0;
    for (int i = k; i <= n; ++i)
    {
        sum += stairSum[n] - stairSum[n - i] - stairSum[i - 1] + 1;
    }
    sum += 1;
    std::cout << sum.x << std::endl;
    return 0;
}