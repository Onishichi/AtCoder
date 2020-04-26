#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

bool check(std::string s1, std::string s2, int d)
{
    bool ret = true;
    for (int i = d; i < std::min<int>(s1.length(), s2.length() + d); ++i)
    {
        if (s1[i] != s2[i - d] && s1[i] != '?' && s2[i - d] != '?')
        {
            ret = false;
            break;
        }
    }
    return ret;
}

int main()
{
    std::array<std::string, 3> abc;
    std::cin >> abc[0] >> abc[1] >> abc[2];
    std::array<std::array<std::array<bool, 4001>, 3>, 3> ok;
    std::array<int, 3> arr = {0, 1, 2};
    do
    {
        for (int j = 0; j <= 4000; ++j)
        {
            ok[arr[0]][arr[1]][j] = check(abc[arr[0]], abc[arr[1]], j);
        }
    } while (std::next_permutation(arr.begin(), arr.end()));

    int ans = 6000;
    do
    {
        for (int j = 0; j <= 2000; ++j)
        {
            if (ok[arr[0]][arr[1]][j])
            {
                for (int k = 0; k <= 2000; ++k)
                {
                    if (ok[arr[1]][arr[2]][k])
                    {
                        if (ok[arr[0]][arr[2]][j + k])
                        {
                            ans = std::min<int>(std::max({abc[arr[0]].length(), j + abc[arr[1]].length(), j + k + abc[arr[2]].length()}), ans);
                        }
                    }
                }
            }
        }
    } while (std::next_permutation(arr.begin(), arr.end()));

    std::cout << ans << std::endl;
    return 0;
}