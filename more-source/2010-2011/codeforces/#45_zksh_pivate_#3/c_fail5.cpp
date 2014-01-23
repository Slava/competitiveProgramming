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
#include <cmath>


using namespace std;


#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define sz(x) x.size()
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define all(x) (x.begin(),x.end())

double minimal_pos = 10, minimp = 1000001;
int n; double a[1009];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lf", &a[i]);
        minimp = min(minimp, (double)((a[i] + 1) * 10 / (i + 1)));
        if (i && a[i] - 1 != a[i - 1])
        {
            minimal_pos = max (minimal_pos, (double)(a[i] * 10 / (i + 1)));
        }
    }
//printf ("%lf %lf\n",double(minimal_pos*(n+1)/10 ),double((minimp-0.1)*(n+1)/10));
    if (floor(double(minimal_pos*(n+1)/10 )) == floor(double((minimp-0.001)*(n+1)/10)))
        printf("unique\n%.0lf", minimal_pos*(n+1)/10);
    else puts("not unique");

    return 0;
}

