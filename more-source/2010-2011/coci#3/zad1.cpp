// Kim Vyacheslav Karaganda KTL
// 2010
// Tablica
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

int main ()
{
    int a, b, c, d, m = 0;
    double res[4];
    scanf ("%d%d%d%d", &a, &b, &c, &d);
    res[0] = (double)a/c + b/d;
    res[1] = (double)c/d + a/b;
    res[2] = (double)d/b + c/a;
    res[3] = (double)b/a + d/c;
    for (int i = 0; i < 4; i++)
        if (res[m] < res[i])
            m = i;
    printf ("%d\n", m);

    return 0;
}

