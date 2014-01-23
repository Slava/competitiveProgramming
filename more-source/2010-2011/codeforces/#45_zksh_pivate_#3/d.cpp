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

long n, a[100009], u[100009], prev = 100009, m, sum;

int main ()
{
    scanf ("%ld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%ld", &a[i]);
        u[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (!u[i]) break;
        else if (prev >= u[i])
                {prev = u[i];sum += u[i];}
            else {cout<<-1;return 0;}
    if (sum != n)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        m = max (m , u[i]);
    printf ("%ld\n", m);

    for (int i = 0; i < n; i++)
    {
        printf ("%ld ", u[a[i]]);u[a[i]]--;
    }

    return 0;
}

