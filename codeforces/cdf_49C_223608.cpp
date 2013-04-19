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

long a, i;

int main ()
{
//    freopen (file".in", "r", stdin);
//    freopen (file".out", "w", stdout);

    cin >> a;
    for (i = 2; i <= a ; i++)
        cout << i << ' ';
    cout << 1;

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 17, 2010 8:00:34 PM
// contest: 49
// link: /contest/49/submission/223608
// time: 60 ms
// verdict: Accepted
// problem: 49C - Disposition
// ID: 223608
// downloaded by very stupid script
