#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

struct Position
{
    double x;
    double y;
};

double distance(Position p1, Position p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

double radius(Position center, Position pos[50], int n)
{
    double maxDist = 0.0;
    for (int i = 0; i < n; ++i)
    {
        double dist = distance(center, pos[i]);
        if (dist > maxDist)
        {
            maxDist = dist;
        }
    }
    return maxDist;
}

double appropriateY(double x, Position pos[50], int n)
{
    double ly = 0.0, ry = 1000.0;
    while (ry - ly > 0.0000000001)
    {
        Position p1, p2;
        p1.x = x;
        p2.x = x;
        p1.y = (ly * 2.0 + ry) / 3.0;
        p2.y = (ly + ry * 2.0) / 3.0;
        if (radius(p1, pos, n) > radius(p2, pos, n))
        {
            ly = p1.y;
        }
        else
        {
            ry = p2.y;
        }
    }
    return (ly + ry) / 2.0;
}

int main()
{
    int n;
    Position pos[50];
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> pos[i].x >> pos[i].y;
    }

    double lx = 0.0, rx = 1000.0;
    Position p1, p2;
    while (rx - lx > 0.0000000001)
    {
        p1.x = (lx * 2.0 + rx) / 3.0;
        p2.x = (lx + rx * 2.0) / 3.0;
        p1.y = appropriateY(p1.x, pos, n);
        p2.y = appropriateY(p2.x, pos, n);
        if (radius(p1, pos, n) > radius(p2, pos, n))
        {
            lx = p1.x;
        }
        else
        {
            rx = p2.x;
        }
    }
    Position center;
    center.x = (p1.x + p2.x) / 2.0;
    center.y = (p1.y + p2.y) / 2.0;

    std::cout << std::setprecision(19) << radius(center, pos, n) << std::endl;
    return 0;
}