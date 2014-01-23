// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, k, a[10], s = 0, t;
    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        a[i] = i;

    do
    {
        t = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == i) t++;
        if (t == k)
            s++;
    } while ( next_permutation(a, a + n) );

    printf ("%d", s);

    return 0;
}

