#include <bits/stdc++.h>

long long solve(long long ai, long long aj, long long bi, long long bj)
{
    long long size = 1;
    for (int i = 0; i < 30; ++i)
    {
        size *= 3;
    }

    long long dist = std::abs(ai - bi) + std::abs(aj - bj);
    while (size > 1)
    {
        size /= 3;
        long long nai = ai / size, naj = aj / size, nbi = bi / size, nbj = bj / size;
        if (nai != nbi)
        {
            break;
        }
        if (std::abs(naj - nbj) >= 2 && nai % 3 == 1)
        {
            long long up = ai - nai * size + 1 + bi - nbi * size + 1;
            long long bottom = (nai + 1) * size - ai + (nbi + 1) * size - bi;
            dist = std::abs(aj - bj) + std::min(up, bottom);
            break;
        }
    }

    return dist;
}

int main()
{
    int q;
    std::cin >> q;
    std::vector<std::array<std::array<long long, 2>, 2>> in(q);
    for (int i = 0; i < q; ++i)
    {
        long long ax, ay, bx, by;
        std::cin >> ax >> ay >> bx >> by;
        --ax;
        --ay;
        --bx;
        --by;
        in[i][0][0] = ax;
        in[i][0][1] = ay;
        in[i][1][0] = bx;
        in[i][1][1] = by;
    }

    for (int i = 0; i < q; ++i)
    {
        std::cout << std::max(solve(in[i][0][0], in[i][0][1], in[i][1][0], in[i][1][1]), solve(in[i][0][1], in[i][0][0], in[i][1][1], in[i][1][0])) << '\n';
    }

    return 0;
}