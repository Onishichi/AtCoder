#include <iostream>
#include <algorithm>
#include <vector>

const int mod = 998244353;
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

std::vector<std::vector<int>> to;

mod_int dfs(int i)
{
    mod_int ret = 1;
    for (int j = 0; j < to[i].size(); ++j)
    {
        ret *= dfs(to[i][j]);
    }
    return ret + 1;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> robot;
    robot.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        robot.push_back(p);
    }

    std::sort(robot.begin(), robot.end());

    std::vector<std::pair<int, int>> xi;
    to.resize(n);
    for (int i = n - 1; i >= 0; --i)
    {
        while (!xi.empty() && xi.back().first < robot[i].first + robot[i].second)
        {
            to[i].push_back(xi.back().second);
            xi.pop_back();
        }
        std::pair<int, int> p(robot[i].first, i);
        xi.push_back(p);
    }

    mod_int ans = 1;
    for (int i = 0; i < xi.size(); ++i)
    {
        ans *= dfs(xi[i].second);
    }

    std::cout << ans.x << std::endl;

    return 0;
}