#include <iostream>
#include <algorithm>

int main()
{
    int n, k, m;
    std::cin >> n >> k >> m;
    int *a = new int[n - 1];
    for (int i = 0; i < n - 1; ++i)
    {
        std::cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        sum += a[i];
    }

    int ans = sum + k >= m * n ? std::max(m * n - sum, 0) : -1;

    std::cout << ans;

    return 0;
}