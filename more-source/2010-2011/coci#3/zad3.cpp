// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k, id;
double a[200], kn, ans;
int main ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            scanf ("%d%lf", &id, &kn);
            id--;
            if (a[id] > -kn)
                a[id] = -kn;
        }
    sort (a, a + n);
    for (int i = 0; i < k; i++)
        ans += a[i];

    printf ("%.1lf ", -ans);

    return 0;
}

