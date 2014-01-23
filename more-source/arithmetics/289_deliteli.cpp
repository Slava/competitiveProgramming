// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define MAXANS 1000000000000001

#define ll __int64
map<vector<ll>, bool>_map;

ll n, a = 9000000000000000, t;
ll p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
            41, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
            97, 101, 103, 107, 109, 113, 127, 131, 137,
            139, 149, 151, 157, 163, 167, 173, 179, 181,
            191, 193, 197, 199};
vector <ll> d, P[300];

ll PP (ll a, ll r)
{
    if (r > P[a].size()) return 0;
    return P[a][r];
}

ll R (vector <ll> d)
{
    ll a = 1, m;
    for (ll i = 0; i < d.size(); i++)
    {
        d[i] = -d[i];
        m = a;
        a *= PP (i, d[i] - 1);
        if (a > MAXANS || a < m)
        {a = 0; break;}
    }
    return a;
}

void D (vector <ll> d)
{
    if (!d.size()) return;
    sort (d.begin(), d.end());
    if (_map.find(d)->second == 1)
        return;
    _map[d] = 1;
    t = R (d);
    if (t)
        a = min (a, t);
    ll tt = d[d.size() - 1];
    d.pop_back();
    for (ll i = 0; i < d.size(); i++)
    {
        d[i] *= tt;
        if (d[i] > 0) d[i] = -d[i];
        D (d);
        d[i] /= tt;
        if (d[i] > 0) d[i] = -d[i];
    }
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (ll i = 2; i <= n; i++)
    {
        if (i * i > n) i = n;
        while (n % i == 0)
        {
            n /= i;
            d.push_back(-i);
        }
    }
    sort (d.begin(), d.end());
    for (ll i = 0; i < d.size(); i++)
    {
        P[i].push_back (1);
        for (ll j = 1; ; j++)
        {
            ll A = P[i][P[i].size() - 1] * p[i];
            P[i].push_back(A);
            if (A > MAXANS || A < P[i][P[i].size() - 2]) break;
        }
        P[i].pop_back();
    }
    D(d);


    if (a == 9000000000000000) a = 0;
    cout << a;

    return 0;
}
