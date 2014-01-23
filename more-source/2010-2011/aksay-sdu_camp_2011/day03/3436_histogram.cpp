#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define mp make_pair

int n, x[16];
pair <int,int> dp[1 << 15][16];
bool k[1 << 15][16];

int S (int prev, int last)
{
    if (x[prev] >= x[last])
        return 2;
    return x[last] * 2 - x[prev] * 2 + 2;
}

pair <int,int> cnt (int mask, int l)
{
    if (k[mask][l])
        return dp[mask][l];
    int msk = mask & (~(1 << l)), i, bit;
    for (i = 0, bit = 1; i < n; i++, bit <<= 1)
    {
        if (msk & bit) {
            pair <int, int> cur = cnt(msk, i);
            if (dp[mask][l].first < cur.first + S(i, l)) {
                dp[mask][l].first = cur.first + S(i, l);
                dp[mask][l].second = cur.second;
            } else if (dp[mask][l].first == cur.first + S(i, l)) {
                dp[mask][l].second += cur.second;
            }
        }
    }
    k[mask][l] = true;
    return dp[mask][l];
}

void solve ()
{
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = mp(0,0);
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            k[i][j] = 0;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int bit = 1, i = 0; i < n; bit <<= 1, i++)
    {
        dp[bit][i] = mp(2 * x[i] + 2, 1);
         k[bit][i] = true;
    }
    pair<int, int> m = mp(0,0);
    int count = 0;
    for (int i = 0; i < n; i++)
        m = max(m, cnt((1 << n) - 1,i));
    for (int i = 0; i < n; i++)
        if (m.first == dp[(1 << n) - 1][i].first)
            count += dp[(1 << n) - 1][i].second;
    cout << m.first << " " <<count << "\n";
}

int main ()
{
    while (cin >> n)
        if(n)
            solve();

    return 0;
}

