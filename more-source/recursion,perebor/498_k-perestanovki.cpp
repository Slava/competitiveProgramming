// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, k, a[10], ans = 0;
    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        a[i] = i;

    do
    {
        bool t = 1;
        for (int i = 1; i < n; i++)
            if (abs (a[i] - a[i - 1]) > k)
            {
                t = 0; break;
            }
        ans += t;
    } while (next_permutation(a, a+n));

    printf ("%d", ans);

    return 0;
}

