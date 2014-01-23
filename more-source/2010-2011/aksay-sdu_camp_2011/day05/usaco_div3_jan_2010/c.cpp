/*
ID: imslavko1
PROG: space
LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, ans, d[] = {0, 1, 1, 0, -1, 0, 0, -1};
char a[1001][1001];
bool u[1001][1001];

void bfs (int i, int j)
{
    queue<int> qi, qj;
    int x, y, dx, dy;
    qi.push(i);
    qj.push(j);
    while (qi.size())
    {
        x = qi.front();
        y = qj.front();
        qi.pop();qj.pop();
        u[x][y] = 1;
        for (int k = 0; k < 8; k += 2)
        {
            dx = x + d[k];
            dy = y + d[k + 1];
            if (dx && dx <= n && dy && dy <= n
                && a[dx][dy] == '*' && !u[dx][dy]){
                qi.push(dx);qj.push(dy);
            }
        }
    }
}

int main ()
{
    freopen ("space.in", "r", stdin);
    freopen ("space.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = n; j; j--)
            a[i][j] = a[i][j - 1];
        a[i][0] = '.';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!u[i][j] && a[i][j] == '*')
            {
                ans++;
                bfs(i,j);
            }
    printf ("%d\n", ans);

    return 0;
}

