#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define sz(x) x.size()
#define cl(x) x.clear()

int n, a[20009], b[20009], i, j, k, check;
bool u[20009];
vector <int> q, z, t;

void d(int x)
{
    u[x] = 1;
    q.pb(x);
    if(!u[b[x]])d(b[x]);
}

int nod(int a, int b)
{
    while(a && b)
    {
        if(a > b)a %=  b;
        else b %= a;
    }
    return a+b;
}

int nok(int a, int b)
{
    return a*b/nod(a,b);
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    for(i = 1; i <= n; i++)
    {
        if(!u[i])d(i);
        if(sz(q) > 1)z.pb(sz(q));
        cl(q);
    }

    while(sz(z) > 1)
    {
        for(i = 0; i < sz(z)-1; i+=2)
            t.pb(nok(z[i],z[i+1]));
        if(sz(z)%2)t.pb(z[sz(z)-1]);
        swap(t, z);cl(t);
    }

    printf("%d", z[0]);

    return 0;
}
