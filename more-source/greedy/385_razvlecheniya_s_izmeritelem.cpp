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
#define all(x) x.begin(),x.end()


// solving must start here

vector <double> b, c;
int n;
struct Point
{
    double x, y;
}a[100];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lf%lf", &a[i].x, &a[i].y);
        for (int j = i-1; j >= 0; j--)
            b.pb(sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)));
    }

    sort(all(b));
    c.pb(b[0]);
    for (int i = 1; i < sz(b); i++)
    {
        if (b[i-1] != b[i])
            c.pb(b[i]);
    }

    printf ("%d\n", sz(c));
    for (int i = 0; i < sz(c); i++)
        printf ("%.9lf\n", c[i]);

    return 0;
}

