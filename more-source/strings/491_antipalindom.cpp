// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>

char s[100009];
int n, p = 1, e = 1;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%s", s);
    n = strlen(s);
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            e = 0;
        if (s[i] != s[n - i - 1])
            p = 0;
    }

    if (p&e)
        puts("NO SOLUTION");
    else if (p)
        printf("%s", s + 1);
    else printf("%s", s);

    return 0;
}

