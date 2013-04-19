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
#define int long long
int rev (int x)
{
    int a = 0;
    for (;x; x /= 10)
    {
        if (x % 10 == 0)
            continue;
        a *= 10;
        a += x % 10;
    }
    return a;
}
int a, b;
main ()
{
    cin >> a >> b;
    int c = a + b;
    a = rev(rev(a));
    b = rev(rev(b));
//    cout << a << " " << b << " " << rev(rev(c));
    if (a + b == rev(rev(c)))
        cout << "YES";
    else cout << "NO";
    return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 13, 2011 9:25:36 PM
// contest: 75
// link: /contest/75/submission/386216
// time: 10 ms
// verdict: Accepted
// problem: 75A - Life Without Zeros
// ID: 386216
// downloaded by very stupid script
