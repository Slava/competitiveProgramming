// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

char s;
long sum[2];

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    for (int i = 0; scanf ("%c", &s) != -1; i++)
        sum[i%2] += s - '0';
    if ((sum[0] - sum[1]) % 11 != 0)
        puts ("NO");
    else puts ("YES");

    return 0;
}
