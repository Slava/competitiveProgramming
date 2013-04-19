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
int ans, n, a[200];
vector<int>odd;

int main ()
{
    cin >> n;
    forn(i,n){
        cin >> a[i];
        if (a[i] & 1)
            odd.pb(a[i]);
        ans += a[i];
    }

    if (odd.empty())
    {
        cout << 0;return 0;
    }

    sort(odd.begin(), odd.end());
    if (ans % 2 == 0)
        ans -= odd[0];
    cout << ans;
    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 11, 2011 7:08:58 PM
// contest: 59
// link: /contest/59/submission/279263
// time: 30 ms
// verdict: Accepted
// problem: 59B - Fortune Telling
// ID: 279263
// downloaded by very stupid script
