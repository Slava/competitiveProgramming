// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

long r, d[400], t[400], l, empty[400], le, j, mask[400];
char s[400], c[] = {'+', '-', '*', '(', ')'};

long _plus_ (long b, long a, long cur)
{

    if (cur == 3)
        return a + b;
    if (cur == 4)
        return b - a;
    if (cur == 5)
        return a * b;
}

long expr ()
{
    long res = 0;
    long cur = 3;
    for (; j < l; j++)
    {
        if (t[j] == 1)
            res = _plus_ (res, d[j], cur);

        else if (t[j] > 2 && t[j] < 6)
            cur = t[j];
        else if (t[j] == 6)
        {
            j++;
            res = _plus_ (res, expr(), cur);
        }
        else if (t[j] == 7)
            break;
    }
    return res;
}

void nextmask ()
{
    int i = 0;
    while (++mask[i] == 3)
        mask[i++] = 0;
}

void print_res ()
{
    printf ("%ld=", r);
    for (int i = 0; i < l; i++)
        if (t[i] == 1)
            printf("%ld", d[i]);
        else printf ("%c", c[t[i] - 3]);
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%ld", &r);
    gets (s);
    long n = strlen (s);

    while (s[n - 1] == ' ') n--;
    while (s[++j] == ' ');
    if (s[j] == '=') while (s[++j] == ' ');
    for (int i = j; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            long T = s[i++] - '0';
            while (s[i] >= '0' && s[i] <= '9')
            {
                T *= 10;
                T += s[i++] - '0';
            }
            t[l] = 1;
            d[l] = T;
            l++;
            i--;
            continue;
        }
        if (s[i] == ' ' && t[l - 1] != 6)
        {
            empty[le++] = l;
            t[l++] = 0;
            while (s[i] == ' ') i++;
            i--;continue;
        }
        if (s[i] == '(')
            t[l++] = 6;
        if (s[i] == ')' && !t[l - 1])
        {
            l--;
            le--;
        }
        if (s[i] == ')')
            t[l++] = 7;
        if (s[i] == '+')
            t[l++] = 3;
        if (s[i] == '-')
            t[l++] = 4;
        if (s[i] == '*')
            t[l++] = 5;
    }

    for (int i = 0; i < pow(3,le); i++)
    {
        for (int k = 0; k < le; k++)
            t[empty[k]] = mask[k] + 3;
        j = 0;
        if (expr() == r)
        {
            print_res();
            return 0;
        }
        nextmask();
    }

    printf ("-1\n");

    return 0;
}
