#include <iostream>
#include <queue>
#include <utility>

int main()
{
    int h, w;
    char s[20][20 + 1];
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i)
    {
        std::cin >> s[i];
    }
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int max = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::queue<std::pair<int, int>> q;
            int d[20][20];
            for (int k = 0; k < h; ++k)
            {
                for (int l = 0; l < w; ++l)
                {
                    d[k][l] = -1;
                }
            }
            if (s[i][j] == '.')
            {
                q.push(std::pair<int, int>(i, j));
                d[i][j] = 0;
                while (q.size())
                {
                    std::pair<int, int> p = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = p.first + dx[k];
                        int y = p.second + dy[k];
                        if (0 <= x && x < h && 0 <= y && y < w && d[x][y] == -1 && s[x][y] == '.')
                        {
                            q.push(std::pair<int, int>(x, y));
                            d[x][y] = d[p.first][p.second] + 1;
                        }
                    }
                }
                for (int k = 0; k < h; ++k)
                {
                    for (int l = 0; l < w; ++l)
                    {
                        if (d[k][l] > max)
                        {
                            max = d[k][l];
                        }
                    }
                }
            }
        }
    }

    std::cout << max;

    return 0;
}