// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n, m, mask[20000], ip[3];
    char s[20000];
    scanf ("%ld", &n);

    for (int i = 0; i < n; i++)
    {
        scanf ("%s", s);
        long t, k = 0;
        for (int j = 0; j < 4; j++)
        {
            t = 0;
            while (s[k] >= '0' && s[k] <= '9')
            {
                t *= 10;
                t += s[k++] - '0';
            }
            k++;
            mask[i] <<= 8;
            mask[i] = mask[i] | t;
        }
    }

    scanf ("%ld", &m);
    for (int i = 0; i < m; i++)
    {
        for (int z = 0; z < 2; z++)
        {
            scanf ("%s", s);
            long t, k = 0;
            for (int j = 0; j < 4; j++)
            {
                t = 0;
                while (s[k] >= '0' && s[k] <= '9')
                {
                    t *= 10;
                    t += s[k++] - '0';
                }
                k++;
                ip[z] <<= 8;
                ip[z] = ip[z] | t;
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++)
            if ((mask[j] & ip[0]) == (mask[j] & ip[1]))
                ans++;
        printf ("%d\n", ans);
    }

    return 0;
}

