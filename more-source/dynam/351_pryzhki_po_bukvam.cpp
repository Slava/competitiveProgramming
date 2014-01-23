// Kim Vyacheslav KarKTL
#include <cstdio>
#define min(a,b) (a<b?a:b)
using namespace std;

char s[100009];
int a[100009], hash[256], pos[256], n, k, m = -1;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d%s", &n, &k, s);
    for (int i = 'A'; i <= 'Z'; i++)
        pos[i] = -100009;

    for (int i = 0; i < n; i++)
    {
        if (i - pos[s[i]] <= k)
            a[i] = hash[s[i]];
        else
        {
            for (int j = 'A'; j <= 'Z'; j++)
                if (i - pos[j] <= k)
                    m = min (m, hash[j]);
            a[i] = m + 1;
        }
        pos[s[i]] = i;
        hash[s[i]] = a[i];
        m = 100009;
    }
    printf ("%d", a[n - 1]);

    return 0;
}
