// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

__int64 a[50][50];
int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, c = 0, more = 1;
    scanf ("%d", &n);
    for (int j = 1; j < n*2; j++){
        for (int i = 1; i <= n + c; i++)
        {
            int I = i + (j > n? j - n:0),
                J = j;
            a[I][J] = a[I - 1][J] + a[I][J - 1] + a[I - 1][J - 1];
            if (!a[I][J])
                a[I][J] = 1;
        }
    if (j == n) more *= -1;
    c += more;
    }

    printf ("%I64d\n", a[n*2-1][n*2-1]);
    return 0;
}
