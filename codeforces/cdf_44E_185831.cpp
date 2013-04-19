// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

int k, A, B, n, m, r, u, j;
char s[500];

int main ()
{
    scanf ("%d%d%d%s", &k, &A, &B, s);
    n = strlen (s);

    m = n / k;
    r = n % k;
    if (k * A > n || k * B < n)
    {
        puts ("No solution");
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        u = m;
        if (r) u++, r--;
        while (u--) printf ("%c", s[j++]);
        printf ("\n");
    }

    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 1, 2010 10:51:06 AM
// contest: 44
// link: /contest/44/submission/185831
// time: 30 ms
// verdict: Accepted
// problem: 44E - Anfisa the Monkey
// ID: 185831
// downloaded by very stupid script
