#include <bits/stdc++.h>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int aSum = 0;
    for (int i = 0; i < m; ++i)
    {
        int a;
        std::cin >> a;
        aSum += a;
    }
    std::cout << std::max(n - aSum,-1) << std::endl;

    return 0;
}