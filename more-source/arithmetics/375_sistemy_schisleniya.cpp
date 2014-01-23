// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

int m, k;
#define MAXSIZE 20000
char set[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char s[MAXSIZE];
// a - initial, b - 10, c - k, r - m^i, t - temp
short a[MAXSIZE], b[MAXSIZE], r[MAXSIZE], t[MAXSIZE];
short c[1000000];

#define F 10

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d%s", &m, &k, s);
    a[0] = strlen (s);
    for (int i = 0; i < a[0]; i++)
        if (s[i] >= '0' && s[i] <= '9') a[a[0] - i] = s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'Z') a[a[0] - i] = s[i] - 'A' + 10;
    r[0] = r[1] = 1;

    for (int i = 1; i <= a[0]; i++)
    {
        // take digit and multiply it by r, sum it to b
        for (int j = 1; j < MAXSIZE; j++)
            t[j] = 0;

        long carry = 0;
        t[0] = r[0];
        for (int j = 1; j <= r[0]; j++)
        {
            t[j] = carry + r[j] * a[i];
            carry = t[j] / F;
            t[j] %= F;
        }
        while (carry)
        {
            t[++t[0]] = carry % 10;
            carry /= 10;
        }
        if (t[0] > b[0]) b[0] = t[0];
        for (int j = 1; j <= t[0]; j++)
        {
            b[j] = b[j] + carry + t[j];
            carry = b[j] / F;
            b[j] %= F;
        }

        while (carry)
        {
            b[++b[0]] = carry % 10;
            carry /= 10;
        }

        // r *= m
        carry = 0;
        for (int j = 1; j <= r[0]; j++)
        {
            r[j] = r[j] * m + carry;
            carry = r[j] / F;
            r[j] %= F;
        }
        while (carry)
        {
            r[++r[0]] = carry % 10;
            carry /= 10;
        }
    }
    c[0] = 0;
    for (; ;)
    {
        // divide b by k and save reminder in array C
        long carry = 0;

        for (int i = b[0]; i; i--)
        {
            b[i] += carry * 10;
            carry = b[i] % k;
            b[i] /= k;
            if (i == b[0] && !b[i]) b[0]--;
        }
        c[++c[0]] = carry;
        if (!b[0]) break;
    }
    for (; c[0] && !c[c[0]]; c[0]--);
    for (int i = c[0]; i >= 1; i--)
        printf ("%c", set[c[i]]);puts("");
    if (!c[0]) printf("0");

    return 0;
}

