#include <iostream>

int main()
{
    long long n, a, b;
    std::cin >> n >> a >> b;
    long long ab = a + b;
    long long var1 = n / ab * a;
    long long var2 = n % ab;
    if (var2 > a)
    {
        var2 = a;
    }
    std::cout << var1 + var2;
    return 0;
}