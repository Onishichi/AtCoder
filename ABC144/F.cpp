#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int main()
{
    const int MAX_N = 600;
    int n, m;
    std::cin >> n >> m;

    struct Room
    {
        std::vector<int> next;
        double e = 0.0;
        double p = 0.0;
    };
    Room *r = new Room[n];

    int *s = new int[m];
    int *t = new int[m];

    for (int i = 0; i < m; ++i)
    {
        std::cin >> s[i] >> t[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == s[j] - 1)
            {
                r[i].next.push_back(t[j] - 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j < r[i].next.size(); ++j)
        {
            r[i].e += r[r[i].next[j]].e;
        }
        r[i].e /= (double)(r[i].next.size());
        r[i].e += 1.0;
    }

    r[0].p = 1.0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < r[i].next.size(); ++j)
        {
            r[r[i].next[j]].p += r[i].p / (double)r[i].next.size();
        }
    }

    double max = 0.0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (r[i].next.size() > 1)
        {
            double sum = 0.0;
            for (int j = 0; j < r[i].next.size(); ++j)
            {
                sum += r[r[i].next[j]].e;
            }

            for (int j = 0; j < r[i].next.size(); ++j)
            {
                double exp = r[i].p * (r[i].e - 1.0 - (sum - r[r[i].next[j]].e) / (double)(r[i].next.size() - 1));
                if (exp > max)
                {
                    max = exp;
                }
            }
        }
    }

    std::cout << std::setprecision(20) << r[0].e - max << std::endl;

    return 0;
}