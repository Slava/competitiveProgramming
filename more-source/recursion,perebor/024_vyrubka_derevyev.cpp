// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, m, ans = 0;
    scanf ("%d%d", &n, &m);

    if (!m)
    {
        printf ("1");
        return 0;
    }
    if (m == 1)
    {
        printf ("%d", n);
        return 0;
    }
    for (int i = 0; i * (m-1) + m <= n; i++)
        ans += n - i * (m - 1) - m + 1;

    printf ("%d", ans);

    return 0;
}

