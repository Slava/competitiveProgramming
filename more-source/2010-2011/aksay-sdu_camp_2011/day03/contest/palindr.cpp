#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

long long d1[200000], d2[200000], sum;
long l, r, n, k, i;
char s[200000];

int main ()
{
    freopen ("palindr.in", "r", stdin);
    freopen ("palindr.out", "w", stdout);

    scanf ("%s", s);
    n = strlen (s);
    for (l = i = 0, r = -1; i < n; i++)
    {
        int k = (i > r ? 0 : min (d1[l + r - i], (long long)r - i)) + 1;
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) ++k;
        d1[i] = --k;
        if (i + k > r)
            l = i - k, r = i + k;

        sum += d1[i];
    }
    for (l = i = 0, r = -1; i < n; i++)
    {
        int k = (i > r ? 0 : min (d2[l + r - i + 1], (long long)r - i + 1)) + 1;
        while (i + k - 1 < n && i - k >= 0 && s[i + k - 1] == s[i - k]) ++k;
        d2[i] = --k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;

        sum += d2[i];
    }

    cout << sum;

    return 0;
}

