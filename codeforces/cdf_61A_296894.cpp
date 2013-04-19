#include <cstdio>
#include <cstring>

char s[500], c[500];
int n, i, a, b;
int main ()
{
    scanf ("%s%s", s, c);
    n = strlen(s);
    for (i = 0; i < n; i++)
    {
        a = s[i] - '0';
        b = c[i] - '0';
        printf("%d", a^b);
    }
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 22, 2011 7:08:05 PM
// contest: 61
// link: /contest/61/submission/296894
// time: 30 ms
// verdict: Accepted
// problem: 61A - Ultra-Fast Mathematician
// ID: 296894
// downloaded by very stupid script
