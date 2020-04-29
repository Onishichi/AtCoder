#include <bits/stdc++.h>

const int max_n = 50;
const int max_s = (max_n - 1) * 50;

struct train
{
    int v, a, b;
    train(int v, int a, int b) : v(v), a(a), b(b) {}
};

struct change
{
    int c, d;
};

struct data
{
    int i, s;
    long long t;
    data(int i, int s, long long t) : i(i), s(s), t(t) {}

    bool operator<(const data &d) const
    {
        return t > d.t;
    }
};

int main()
{
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<train> t[max_n];
    for (int i = 0; i < m; ++i)
    {
        int u, v, a, b;
        std::cin >> u >> v >> a >> b;
        --u;
        --v;
        t[u].emplace_back(v, a, b);
        t[v].emplace_back(u, a, b);
    }

    change c[max_n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c[i].c >> c[i].d;
    }

    long long time[max_n][max_s + 1];
    for (int i = 0; i < max_n; ++i)
    {
        std::fill(time[i], time[i] + max_s + 1, LONG_LONG_MAX);
    }

    std::priority_queue<data> q;
    auto push = [&](int i, int s, long long t) {
        int mins = std::min(s, max_s);
        if (mins < 0)
        {
            return;
        }
        if (time[i][mins] <= t)
        {
            return;
        }
        time[i][mins] = t;
        q.emplace(i, mins, t);
    };
    push(0, s, 0);

    while (!q.empty())
    {
        data d = q.top();
        q.pop();
        if (d.t > time[d.i][d.s])
        {
            continue;
        }

        for (int j = 0; j < t[d.i].size(); ++j)
        {
            push(t[d.i][j].v, d.s - t[d.i][j].a, d.t + t[d.i][j].b);
        }
        push(d.i, d.s + c[d.i].c, d.t + c[d.i].d);
    }

    for (int i = 1; i < n; ++i)
    {
        long long min = LONG_LONG_MAX;
        for (int j = 0; j <= max_s; ++j)
        {
            min = std::min(time[i][j], min);
        }
        std::cout << min << std::endl;
    }

    return 0;
}