// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

bool u[50001] = {1};
int n, i, j, a;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &a);
        for (j = 50000; j >= 0; j--)
            if (u[j])
                u[j + a] = 1;
    }
    a = 0;
    for (i = 0; i < 50001; i++)
        a += u[i];
    printf ("%d", a);

    return 0;
}

