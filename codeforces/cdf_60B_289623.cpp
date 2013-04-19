// Kim Vyacheslav
// 2011
#include <cstdio>
#include <iostream>

#include <cmath>
#include <cstring>
#include <algorithm>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)
#define all(x) (x.begin(),x.end())
#define pb push_back
#define sqr(x) (x)*(x)

#define dbg(x) cout<<#x<<" = "<<x<<" "
#define forn(i,n) for(int i = 0; i < n; i++)
#define ford(i,n) for(int i = n - 1; i >= 0; i--)
const int inf = 1 << 30;
#define X to.x
#define Y to.y
#define Z to.z
struct cl
{
    int x, y, z;
};
const int maxn = 200;
long n, m, k, sx, sy, ans;
long d[] = {0,0,1, 0,0,-1, 0,1,0, 0,-1,0, 1,0,0, -1,0,0};
bool u[maxn][maxn][maxn];
char can[maxn][maxn][maxn];
queue<cl>q;

int main ()
{
    scanf ("%ld%ld%ld", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf ("%s", can[i][j]);
    scanf ("%ld%ld", &sx, &sy);
    cl start, cur, to;
    start.y = sx - 1;
    start.z = sy - 1;
    start.x = 0;
    u[0][sx-1][sy-1] = 1;
    q.push(start);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (can[cur.x][cur.y][cur.z] != '.')
            continue;
        ans++;
//        printf("%ld %ld %ld\n", cur.x,cur.y,cur.z);
        for (int i = 0; i < 18; i += 3)
        {
            to = cur;
            to.x += d[i];
            to.y += d[i + 1];
            to.z += d[i + 2];
            if (0 <= X && X < n &&
                0 <= Y && Y < m &&
                0 <= Z && Z < k && !u[X][Y][Z] && can[X][Y][Z] == '.')
            {
                u[X][Y][Z] = 1;
                q.push(to);
            }
        }
    }
    printf("%ld\n", ans);
    return 0;
}





// lang: GNU C++
// memory: 17000 KB
// author: imslavko
// submit_date: Feb 19, 2011 7:44:08 PM
// contest: 60
// link: /contest/60/submission/289623
// time: 30 ms
// verdict: Accepted
// problem: 60B - Serial Time!
// ID: 289623
// downloaded by very stupid script
