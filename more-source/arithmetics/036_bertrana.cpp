// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

bool p[120000];
int n, ans;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);

    p[0] = p[1] = 1;
    for (int i = 2; i <= 2*n; i++)
        if (!p[i])
            for (int j = i + i; j <= 2*n; j += i)
                p[j] = 1;
    for (int i = n + 1; i < 2*n; i++)
        ans += !p[i];
    printf ("%d", ans);

    return 0;
}
