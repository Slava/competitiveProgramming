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

struct Bad
{
    int a, b, c;
}bad[100009];
int n,m,k;
string s,t;
char cs[2000000];
bool g[3009][3009], b[3009][3009];
int pr[3009];
int main ()
{
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> n >> m >> k;
    while(scanf("%s", cs) == 1)
    {
        t = cs;
        s+=t+' ';
    }

    stringstream S(s), N(s);
    forn(i,m)
        S >> t >> t >> t;
    forn(i,k)
    {
        S >> bad.a >> bad.b >> bad.c;

    }
    forn(i,m)
    {
        f
    }

    return 0;
}

