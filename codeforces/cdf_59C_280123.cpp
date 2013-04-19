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

bool was[30];
int q[200], qn, qh,sum;

int main ()
{
    string s;
    int k, isP = 1;
    cin >> k >> s;
    int n = s.size();
    for(int i = 0; i < (n+1)/2; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            was[s[i] - 'a'] = 1;
        if (s[n-i-1] >= 'a' && s[n-i-1] <= 'z')
            was[s[n-i-1] - 'a'] = 1;
        if (s[i] == '?' || s[n-i-1] == '?')
        {
            if (s[i] == '?' && s[n-i-1] == '?')
            {
                q[qn++] = i;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
                s[n-i-1] = s[i];
            else if (s[n-i-1] >= 'a' && s[n-i-1] <= 'z')
                s[i] = s[n-i-1];
            continue;
        }
        if (s[i] != s[n-i-1])
            {isP = 0;}
    }
    if (!isP)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    forn(i,k)sum+=!was[i];
//    cerr<<qn-qh<<" -> "<<sum<<"\n";
    if (sum > qn)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (; qh < qn && qn-qh > sum; qh++)
    {
        int v = q[qh];
        s[v] = s[n-v-1] = 'a';
    }
    forn(i,k)
    {
        if (was[i])
            continue;
        int v = q[qh++];
        s[v] = s[n-v-1] = 'a' + i;
    }
    cout << s;

    return 0;
}
// 0123456
// a??a




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 11, 2011 7:37:29 PM
// contest: 59
// link: /contest/59/submission/280123
// time: 30 ms
// verdict: Accepted
// problem: 59C - Title
// ID: 280123
// downloaded by very stupid script
