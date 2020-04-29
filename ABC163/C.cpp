#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    a[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> a[i];
    }

    std::vector<int> ans(n);
    std::fill(ans.begin(), ans.end(), 0);
    for (int i = 1; i < n; ++i)
    {
        ++ans[a[i] - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << ans[i] << '\n';
    }
    return 0;
}