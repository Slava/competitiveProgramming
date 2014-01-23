#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define abs(x) ((x)<0?-(x):(x))

struct point
{
    int x, y;
    point(){x = y = 0;}
    bool heard;
}jury, agents[2000];
int n, k, ans;
char ch;

void check (int i)
{
    agents[i].heard = (abs(agents[i].x - jury.x) <= 1) &&
                      (abs(agents[i].y - jury.y) <= 1);
}

int main ()
{
    freopen ("uhode.in", "r", stdin);
    freopen ("uhode.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> agents[i].x >> agents[i].y;
        check(i);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> ch;
        if (ch == 'S') jury.y++;
        if (ch == 'J') jury.y--;
        if (ch == 'Z') jury.x--;
        if (ch == 'I') jury.x++;
        for (int j = 0; j < n; j++)
            if (!agents[j].heard)
                check(j);
    }
    for (int i = 0; i < n; i++)
        ans += agents[i].heard;

    if (!ans)
        cout << -1;
    else for (int i = 0; i < n; i++)
        if (agents[i].heard)
            cout << i + 1 << "\n";

    return 0;
}

