// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>

int root(int k)
{
    for(int t = 0; k > 9; k = t, t = 0)
        while(k)
            t += k % 10, k /= 10;
    return k;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char s[200];
    scanf ("%s", s);
    int n = strlen(s), i, S = 0, T = 0;
    for (i = 0; i < n; i++)
        S += s[i] - '0';
    for (i = 0; i < n - 1; i++)
    {
        S -= s[i] - '0';
        T += s[i] - '0';
        if (root(S) == root(T))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}

