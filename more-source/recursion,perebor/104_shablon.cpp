// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[300][300], n, m;
char x[300], y[300], *A, *B;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%s%s", x, y);
    A = x;
    B = y;
    n = strlen (A);
    m = strlen (B);

    for (int i = 0; i < m; i++)
        if (B[i] == '?' || B[i] == '*')
        {
            swap(A,B);
            swap(n,m);
            break;
        }

    for (int i = 0; i < n; i++)
        a[i][0] = A[i] == B[0] || A[i] == '?' ;
    for (int i = 0; i < m; i++)
        a[0][i] =  A[0] == B[i] || A[0] == '?' ;
    for (int i = 0; A[0] == '*' && i < m; i++)
        a[0][i] = i + 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (A[i] == B[j] || A[i] == '?')
                a[i][j] = a[i-1][j-1] + 1;
            else if (A[i] == '*')
                a[i][0] = 1, a[i][j] = max(a[i-1][j-1], a[i][j-1]) + 1;
    if (a[n-1][m-1] == m)
        puts("YES");
    else
        puts("NO");

    return 0;
}
