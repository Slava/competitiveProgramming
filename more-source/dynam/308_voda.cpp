// Kim Vyacheslav Karaganda KTL
// 2010
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

#define mp make_pair

long a[2001][2001];
long v[3], t, x, y, ans = 7777777;
queue<pair<long, long> >q;

void test (long _x, long _y)
{
    if (_x >= 0 && _y >= 0 &&
        _y <= v[1] && (_x + _y) <= v[0] &&
        v[0] - _y - _x <= v[2] && !a[_x][_y])
    {
        a[_x][_y] = a[x][y] + 1;
        q.push(mp(_x, _y));
    }
}

main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> v[0] >> v[1] >> v[2] >> t;
    a[v[0]][0] = 1;
    q.push(mp(v[0], 0));

    while (q.size())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x == t)
            ans = min (ans, a[x][y] - 1);
        // 1->2
        if (x + y <= v[1]) test (0, x + y);
        else test (x + y - v[1], v[1]);
        // 2->1
        test (x + y, 0);
        // 1->3
        if (v[0] - y <= v[2]) test (0, y);
        else test (v[0] - v[2] - y, y);
        // 2->3
        if (v[0] - x <= v[2]) test (x, 0);
        else test (x, v[0] - v[2] - x);
        // 3->1
        test (v[0] - y, y);
        // 3->2
        if (v[0] - x <= v[1]) test (x, v[0] - x);
        else test (x, v[1]);
    }

    if (ans == 7777777)
        cout << "IMPOSSIBLE";
    else cout << ans;

    return 0;
}

