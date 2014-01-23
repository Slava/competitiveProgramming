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
#define pb push_back
#define sqr(x) (x)*(x)

#define dbg(x) cout<<#x<<" = "<<x<<" "
#define forn(i,n) for(int i = 0; i < n; i++)
#define ford(i,n) for(int i = n - 1; i >= 0; i--)
const int inf = 1 << 30;

int a, b, d;

vector<int> all;

int bs (int x)
{
    int l, r, m;
    l = 0; r = all.size() - 1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (all[m] <= x)
            l = m + 1;
        else r = m - 1;
    }
    return l - 1;
}

int main ()
{
    cin >> a >> b;
    d = __gcd(a, b);
    for(int i = 1; i * i <= d; i++)
        if (d % i == 0)
            all.push_back(i), all.push_back(d/i);
    sort(all.begin(), all.end());
    int n, low, up;
    cin >> n;
    for(;n--;)
    {
        cin >> low >> up;
        int ans = bs(up);
        if (ans == -1 || !(all[ans] >= low && all[ans] <= up))
            cout << "-1\n";
        else cout << all[ans] << "\n";
            }
    return 0;
}

