#include <cstdio>

long n, p[5090], w[5090], e, f, v[100009], m, ans, can[100009];
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld%ld%ld", &e, &f, &n);
    m = f - e;

    if (e >= f)
    {
        puts ("This is impossible.");
        return 0;
    }

    for (int i = 0; i < n; i++)
        scanf ("%ld%ld", &p[i], &w[i]);

    for (int i = 0; i < n; i++) v[w[i]] = max(p[i], v[w[i]]);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < n; j++)
            if (v[i] && i + w[j] <= m && v[i] + p[j] > v[i + w[j]])
                v[i + w[j]] = v[i] + p[j];

    if (!v[m])
    {
        puts ("This is impossible.");
        return 0;
    }

    ans = v[m];
    for (int i = 1; i <= m; i++)
        v[i] = 9999999;

    for (int i = 0; i < n; i++) v[w[i]] = min (v[w[i]], p[i]);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j < n; j++)
            if (v[i] != 9999999 && i + w[j] <= m && v[i] + p[j] < v[i + w[j]])
                v[i + w[j]] = v[i] + p[j];



    printf ("%ld %ld\n", v[m], ans);

    return 0;
}

