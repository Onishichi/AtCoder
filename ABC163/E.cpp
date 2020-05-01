#include <bits/stdc++.h>

int main()
{
    const int MAX_N = 2000;
    int n;
    std::cin >> n;
    std::pair<long long, int> a[MAX_N];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a, a + n);
    long long ans[MAX_N][MAX_N];
    for (int j = 0; j < n; ++j)
    {
        ans[0][j] = a[0].first * std::abs(a[0].second - j);
    }

    //a[i]
    for (int i = 1; i < n; ++i)
    {
        //埋まっている先頭の数
        for (int j = 0; i + j < n; ++j)
        {
            long long front = ans[i - 1][j + 1] + a[i].first * std::abs(a[i].second - j);
            long long back = ans[i - 1][j] + a[i].first * std::abs(a[i].second - (j + i));
            ans[i][j] = std::max(front, back);
        }
    }

    std::cout << ans[n - 1][0] << std::endl;
    return 0;
}