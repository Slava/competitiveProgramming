// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

#define maxn 100009
#define res(i) (!i?0:res[i-1])

int g[maxn], n, m, b[maxn], v[maxn], res[maxn], a[maxn], u[maxn];

int main ()
{
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%d", &g[i]);
    for (int i = 0; i < m; i++)
        scanf ("%d", &v[i]);
    for (int i = 0; i < m; i++)
        scanf ("%d", &b[i]);
    for (int i = 0; i < m; i++)
    {
        a[i] = (v[i] + res(i) - 1) % n;
        while (b[i])
        {
            if (b[i] <= u[a[i]]) break;
//            printf ("a[i]=%d, b[i]=%d, u[a[i]]=%d\n",a[i]+1,b[i], u[a[i]]);
            if (!u[a[i]])
                res[i]++;
            u[a[i]] = b[i];
            b[i]--;
            a[i] = g[a[i]] - 1;
        }
        printf ("%d\n", res[i]);
    }

    return 0;
}




// lang: GNU C++
// memory: 3600 KB
// author: imslavko
// submit_date: Nov 23, 2010 5:53:27 PM
// contest: 45
// link: /contest/45/submission/196121
// time: 140 ms
// verdict: Accepted
// problem: 45B - School
// ID: 196121
// downloaded by very stupid script
