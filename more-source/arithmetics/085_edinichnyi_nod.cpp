// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

int n, m, a;

int nod (int a, int b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else b %= a;
    }
    return a + b;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d%d", &n, &m);
    a = nod (n, m);
    for (int i = 0; i < a; i++)
        printf ("1");

    return 0;
}

