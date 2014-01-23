// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;


long s[1000009];
long ed, n, carry, i;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char S[1000009];

    scanf ("%ld%s", &n, S);

    for (i = 0; i < n; i++)
        if (S[i] == '1') ed++;
    for (i = 0; i < n; i++)
    {
        s[i] = carry + ed;
        carry = s[i] / 2;
        if (s[i] % 2 == 0)
            s[i] = 1;
        else s[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        s[i]++;
        if (s[i] > 1)
            s[i] = 0;
        else break;
    }

    for (i = n - 1; i && !s[i]; i--);
    for (; i >= 0; i--)
        printf ("%ld", s[i]);

    return 0;
}

