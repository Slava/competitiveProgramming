#include <cstdio>

long n, a[1000000], i, m, j, one = 1, b, ch, ans;

int main ()
{
    scanf ("%ld", &n);
    m = (n + 1) / 2;
    m--;
    ch = n & 1;
    for (; i < n; i++)
    {
        scanf ("%ld", &b);
        if (b - j > 0)
        {
            a[b - j]++;
            if (ans < a[b - j])
                ans = a[b - j];
        }
        if (j == m)
            if (!ch)
                ch = 1, j -= one;
            else
                one = -one;
        j += one;
    }
    printf("%ld", n - ans);
    return 0;
}




// lang: GNU C++
// memory: 5200 KB
// author: imslavko
// submit_date: Jan 31, 2011 7:49:26 PM
// contest: 58
// link: /contest/58/submission/270094
// time: 60 ms
// verdict: Accepted
// problem: 58C - Trees
// ID: 270094
// downloaded by very stupid script
