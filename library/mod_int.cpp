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