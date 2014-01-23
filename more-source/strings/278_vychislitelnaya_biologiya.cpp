// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n, m, i, j;
    char s[360000], t[360000];
    scanf ("%s%s", t, s);
    n = strlen(s);
    m = strlen(t);

    if (m > n)
    {
        puts("NO");
        return 0;
    }
    for(i = j = 0; i < n && j < m; i++)
        if (s[i] == t[j])
            j++;
    puts(j == m ? "YES" : "NO");
    return 0;
}

