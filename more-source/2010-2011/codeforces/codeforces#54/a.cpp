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
int big, small;

int main ()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.size() ; i++)
        if (a[i] >='A' && a[i]<='Z')
            big++;
        else small++;
    if (big > small)
        for (int i = 0; i < a.size() ;i++)
            if (a[i] >='A' && a[i]<='Z')
                cout << a[i];
            else cout << (char)(a[i] - 'a' + 'A');
    else
        for (int i = 0; i < a.size() ;i++)
            if (a[i] >='A' && a[i]<='Z')
                cout << (char)(a[i] - 'A' + 'a');
            else cout << a[i];

    return 0;
}

