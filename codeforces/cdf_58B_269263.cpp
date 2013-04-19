#include <cstdio>

int main ()
{
    int n, a, i;
    scanf("%d", &n);
    for (a = n; a > 1; a--)
    {
        if (n % a == 0)
        {
            printf("%d ", a);
            n = a;
        }
    }
    puts("1");
    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 31, 2011 7:20:28 PM
// contest: 58
// link: /contest/58/submission/269263
// time: 30 ms
// verdict: Accepted
// problem: 58B - Coins
// ID: 269263
// downloaded by very stupid script
