#include <iostream>
#include <algorithm>
#include <cmath>

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

#include <vector>
#include <cassert>
struct combination
{
    std::vector<mod_int> fact, ifact;
    combination(int n) : fact(n + 1), ifact(n + 1)
    {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
    }
    mod_int operator()(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

int main()
{
    int n, k;
    int a[100000];
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    mod_int sum_max = 0;
    mod_int sum_min = 0;
    combination comb(n);
    for (int i = k - 1; i < n; ++i)
    {
        sum_max += comb(i, k - 1) * a[i];
    }
    for (int i = 0; i < n - k + 1; ++i)
    {
        sum_min += comb(n - i - 1, k - 1) * a[i];
    }

    std::cout << (sum_max - sum_min).x << std::endl;
    return 0;
}