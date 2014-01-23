// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

int nod (int a, int b)
{
    while (a && b)
        if (a > b)
            a %= b;
        else b %= a;
    return a + b;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int a, b;
    scanf ("%d%d", &a, &b);
    printf ("%d", a * b / nod (a,b));

    return 0;
}

