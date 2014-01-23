#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<vector<int> > a[2], can, msp;
int d[] = {0, 1, 1, 0, -1, 0, 0, -1};
int n, m, sx, sy, enemymoves=1;
char s[32009];

void move_enemy(char c)
{
    can[sy][sx] = 1;
    if (c == 'D')
        sy++;
    if (c == 'U')
        sy++;
    if (c == 'L')
        sx--;
    if (c == 'R')
        sx++;
    can[sy][sx] = 0;
    if (sy == n- 1&& sx == m - 1)
    {
        can[sy][sx] = 1;
        enemymoves = 0;
    }
}

void try_move(int y, int x, int k, int moves)
{
    int dx, dy;
    for (int i = 0; i < 8; i += 2)
    {
        dx = x + d[i];
        dy = y + d[i + 1];
        if (dx >= 0 && dx < m)
            if (dy >= 0 && dy < n)
                if (can[dy][dx])
                    a[k][dy][dx] = min(moves, a[k][dy][dx]);
    }
}

void check()
{
    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    int dx, dy, x, y;

    msp[0][0] = 0;
    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i += 2)
        {
            dx = x + d[i];
            dy = y + d[i + 1];
            if (dx >= 0 && dx < m)
                if (dy >= 0 && dy < n)
                    if (can[dy][dx] && msp[dy][dx] > msp[y][x] + 1)
                    {
                        msp[dy][dx] = msp[y][x] + 1;
                        q.push(make_pair(dy,dx));
                    }
        }
    }
    if (msp[n - 1][m - 1] == 7777777)
    {
        puts("-1");
        exit(0);
    }
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d", &n, &m);
    can.assign(n, vector<int>(m, 0));
    msp.assign(n, vector<int>(m, 7777777));
    a[0].assign(n, vector<int>(m, 7777777));
    a[1].assign(n, vector<int>(m, 7777777));
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", s);
        for (int j = 0; j < m; j++)
            can[i][j] = (s[j] == '.');
    }
    scanf ("%d%d%s", &sy, &sx, s);

    check();
    sx--;sy--;
    can[sy][sx] = 0;

    a[0][0][0] = 0;
    for (int k = 1; k <= n * m + 1; k++)
    {
        a[k%2].clear();
        a[k%2].assign(n, vector<int>(m, 7777777));
        if (a[(k + 1)%2][n - 1][m - 1] != 7777777)
        {
            cout << k - 1;
            break;
        }
        if(k - 1 < strlen(s) && enemymoves)
            move_enemy(s[k - 1]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(can[i][j])
                    try_move(i, j, k%2,a[(k+1)%2][i][j]+1);

    }


    return 0;
}

