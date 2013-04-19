// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
/*
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
*/

using namespace std;

/*
#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define sz(x) x.size()
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define all(x) (x.begin(),x.end())
*/

// solving must start here

int main ()
{
    int n, c = 1;
    scanf ("%d", &n);
    for (int i = 1; i < n; i++)
    {
        c += i;
        if (c > n)
            c -= n;
        printf ("%d ", c);
    }

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 5, 2010 11:12:25 AM
// contest: 46
// link: /contest/46/submission/206485
// time: 30 ms
// verdict: Accepted
// problem: 46A - Ball Game
// ID: 206485
// downloaded by very stupid script
