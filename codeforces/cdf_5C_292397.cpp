// Kim Vyacheslav Karaganda KTL
#include <cstdio>

const int N = 1000010;
char s[N];
int i, mx, mn, a[N];
int main ()
{
    gets(s);
    for (; s[++i] != '\0';)
    {
        if (s[i] == ')')
        {
            if (s[i - 1 - a[i - 1]] == '(')
                a[i] = 2  + a[i - 1];
            if (s[i - a[i]] == ')')
                a[i] += a[i - a[i]];
        }
        if (a[i] == mx)
            mn++;
        if (a[i] > mx)
            mx = a[i], mn = 1;
        }
    printf("%d %d", mx, mx?mn:1);
    return 0;
}





// lang: GNU C++
// memory: 6200 KB
// author: imslavko
// submit_date: Feb 20, 2011 12:36:42 PM
// contest: 5
// link: /contest/5/submission/292397
// time: 50 ms
// verdict: Accepted
// problem: 5C - Longest Regular Bracket Sequence
// ID: 292397
// downloaded by very stupid script
