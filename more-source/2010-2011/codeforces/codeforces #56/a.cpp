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

char clue[2000][100];
int n, m, cl[2000], l, r;
int main ()
{
    scanf ("%d %d\n", &n, &m);
    l = 0; r = n + 1;
    for (int i = 0; i < m; i++)
    {
        scanf ("To the %s of %d\n", clue[i], cl + i);
        if (!strcmp(clue[i], "right"))
                l = max(cl[i], l);
        else r = min (r, cl[i]);
    }
//    printf("%d %d\n", l, r);
    if (r - l - 1 <= 0)
        puts("-1");
    else printf("%d\n", r - l - 1);
    return 0;
}

