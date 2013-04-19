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
unsigned long long n;
int main ()
{
    int minus = 0;
    string s;
    cin >> s;
    if (s[0] == '-')
    {
        s = s.substr(1, s.size() - 1);
        minus = 1;
    }
    if(minus)
    {
        if (s.size() > 19 || s > "9223372036854775808")
            cout << "BigInteger";
    }
    else if (s.size() > 19 || s > "9223372036854775807")
        cout << "BigInteger";
    else{
        stringstream Sin(s);
        Sin >> n;
        if (n > 2147483647 + minus)
        {
            cout << "long";
        }
        else if (n > minus + 32767)
            cout << "int";
        else if (n > minus + 127 )
            cout << "short";
        else cout << "byte";
    }
        return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Mar 7, 2011 8:36:23 PM
// contest: 66
// link: /contest/66/submission/326522
// time: 30 ms
// verdict: Accepted
// problem: 66A - Petya and Java
// ID: 326522
// downloaded by very stupid script
