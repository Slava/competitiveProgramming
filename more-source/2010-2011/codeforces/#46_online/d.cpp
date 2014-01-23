// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <cstring>


using namespace std;


#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define sz(x) x.size()
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define all(x) (x.begin(),x.end())

#define file ""

char a[100000];
int n, s1, s2, e;

int main ()
{
//    freopen (file".in", "r", stdin);
//    freopen (file".out", "w", stdout);

    cin >> n;
    cin >> a;


    for (int i  = 0; i < n; i++)
    {
        e = (i%2);
        if (a[i] == (e + '0'))s1++;
        else s2++;
    }

    cout << min (s1, s2);
    return 0;
}

