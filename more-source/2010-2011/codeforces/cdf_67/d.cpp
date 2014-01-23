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

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define all(x) (x.begin(),x.end())
#define pb push_back
#define sqr(x) (x)*(x)

#define dbg(x) cout<<#x<<" = "<<x<<" "
#define forn(i,n) for(int i = 0; i < n; i++)
#define ford(i,n) for(int i = n - 1; i >= 0; i--)
long long inf = 99999999999999999LL;

#ifdef ONLINE_JUDGE
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

void proc (long long a[7000], int n, long long &L, long long &R, long long &ALL, long long &M)
{
    L = R = M = -inf;
    forn(i, n)
        ALL += a[i];
    long long sum = 0;
    forn(i,n){
        sum += a[i];
        L = max(L, sum);
    }
    sum = 0;
    ford(i, n){
        sum += a[i];
        R = max(R, sum);
    }
    sum = 0;
    forn(i, n){
        sum = max(sum + a[i], a[i]);
        M = max(M, sum);
    }
}

long long c[70][7000], L[70], R[70], M[70], ALL[70], B, UN;
int n, m, l[70], a[260000];
int main ()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", l + i);
        for (int j = 0; j < l[i]; j++)
            scanf(i64, &c[i][j]);
    }
    forn(i, m)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        proc(c[i], l[i], L[i], R[i], ALL[i], M[i]);
    forn(i, m)
        a[i]--;
    B = -inf;
    forn(i, m)
    {
        B = max(UN + L[a[i]], B);
        UN = max(UN + ALL[a[i]], R[a[i]]);
        B = max(B, M[a[i]]);
    }
    printf(i64, B);
    return 0;
}

