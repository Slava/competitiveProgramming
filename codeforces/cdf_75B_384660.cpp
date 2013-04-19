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

string my, a, b, c, d, e;
map<string, int> m;
int n;
vector<pair<int, string> >ans;
int main ()
{
    cin >> my >> n;
    forn(i, n)
    {
        cin >> a >> b;
        if (b != "likes")
            cin >> c;
        cin >> c >> d;
        c.erase(c.size() - 2, 2);
        int how;
        if (b == "posted")
            how = 15;
        if (b == "commented")
            how = 10;;
        if (b == "likes")
            how = 5;
        if (a == my && c != my)
            m[c] += how;
        if (a != my && c == my)
            m[a] += how;
        if(a != my)
            m[a] += 0;
        if (c != my)
            m[c] += 0;
    }
    for(map<string, int>::iterator i = m.begin(); i != m.end(); i++)
        ans.push_back(make_pair(- i->second, i->first));
    sort(ans.begin(), ans.end());
    forn(i,ans.size())
        cout << ans[i].second << "\n";
    return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 13, 2011 8:00:06 PM
// contest: 75
// link: /contest/75/submission/384660
// time: 30 ms
// verdict: Accepted
// problem: 75B - Facetook Priority Wall
// ID: 384660
// downloaded by very stupid script
