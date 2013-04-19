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





// lang: GNU C++
// memory: 2000 KB
// author: imslavko
// submit_date: Dec 17, 2010 8:44:34 PM
// contest: 49
// link: /contest/49/submission/224233
// time: 30 ms
// verdict: Accepted
// problem: 49D - Game
// ID: 224233
// downloaded by very stupid script
