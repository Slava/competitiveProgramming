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

int n, a[2000], m;

int get (int x)
{
    int r = 1;
    for (int i = x - 1; i >= 0; i--)
        if (a[i] > a[i + 1])
            break;
        else r++;
    for (int i = x + 1; i < n; i++)
        if (a[i] > a[i - 1])
            break;
        else r++;
    return r;
}

int main ()
{
    scanf ("%d", &n);
    forn (i,n)
        scanf("%d", a + i);
    forn (i,n)
        m = max(m,get(i));
    printf("%d", m);
    return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Mar 7, 2011 7:08:29 PM
// contest: 66
// link: /contest/66/submission/323813
// time: 30 ms
// verdict: Accepted
// problem: 66B - Petya and Countryside
// ID: 323813
// downloaded by very stupid script
