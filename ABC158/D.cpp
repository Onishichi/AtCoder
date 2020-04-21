#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    s.reserve(100001);
    int q;

    std::cin >> s;
    std::cin >> q;
    bool isAlign = true;
    std::string front, back;
    front.reserve(200001);
    back.reserve(200001);
    for (int i = 0; i < q; ++i)
    {
        int t;
        std::cin >> t;
        if (t == 1)
        {
            isAlign = !isAlign;
        }
        else
        {
            int f;
            char c;
            std::cin >> f;
            std::cin >> c;
            if (f == 1)
            {
                if (isAlign)
                {
                    front.push_back(c);
                }
                else
                {
                    back.push_back(c);
                }
            }
            else
            {
                if (isAlign)
                {
                    back.push_back(c);
                }
                else
                {
                    front.push_back(c);
                }
            }
        }
    }
    std::string ans;
    ans.reserve(300001);
    std::reverse(front.begin(), front.end());
    ans = front + s + back;
    if (!isAlign)
    {
        std::reverse(ans.begin(), ans.end());
    }
    std::cout << ans << std::endl;
    return 0;
}