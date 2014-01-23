#include <cstdio>

using namespace std;

int main ()
{
    int n, c = 0;
    char a[2000];

    scanf ("%d%s", &n, a);

    if (a[n - 1] != a[0]) c++;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            c++;
    printf ("%d", c / 4);

    return 0;
}

