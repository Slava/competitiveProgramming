// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int a[50], n;

void p (int i = 0, int m = 1, int l = n)
{
    if (!l)
    {
        if (i == 1)return;
        for (int j = 0; j < i - 1; j++)
            printf ("%d+", a[j]);
        printf ("%d\n", a[i - 1]);
        return;
    }
    for (; m <= l; m++)
    {
        a[i] = m;
        p (i + 1, m, l - m);
    }
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);
    p(0, 1, n);

    return 0;
}

