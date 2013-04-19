#include <cstdio>
int n, a[101010], s, c, ans, l, r, i;
int main ()
{
    scanf ("%d", &n);
    l = 0, r = n - 1;
    for (i = 0; i < n; i++)
        scanf ("%d", a + i);
    while (l <= r)
        if (s <= c)
            s += a[l++];
        else c += a[r--];
    printf("%d %d", l, n - l);
  }



// lang: GNU C++
// memory: 1700 KB
// author: imslavko
// submit_date: Feb 21, 2011 5:39:59 PM
// contest: 6
// link: /contest/6/submission/293551
// time: 60 ms
// verdict: Accepted
// problem: 6C - Alice, Bob and Chocolate
// ID: 293551
// downloaded by very stupid script
