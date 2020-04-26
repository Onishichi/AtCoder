#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    std::string s;
    s.resize(n);
    std::fill(s.begin(), s.end(), 'a');
    while (s[0] == 'a')
    {
        bool b = true;
        std::cout << s << '\n';
        for (int i = 1; i <= n; ++i)
        {
            bool flag = false;
            for (int j = 0; j < n - i; ++j)
            {

                if (s[j] == s[n - i])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                s[n - i] += 1;
                for (int j = n - i + 1; j < n; ++j)
                {
                    s[j] = 'a';
                }
                break;
            }
            if (i == n)
            {
                b = false;
            }
        }
        if (!b)
        {
            break;
        }
    }
    return 0;
}