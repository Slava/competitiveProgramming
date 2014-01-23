// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

char s[5], t[5];
int p[255], b, k;
int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    for (int i = 0; i < 255; i++)
        p[i] = -1;
    scanf ("%s", s);
    for (int i = 0; i < 4; i++)
        p[s[i]] = i;
    scanf ("%s", t);
    for (int i = 0; i < 4; i++)
        if (s[i] == t[i])
            b++;
        else if (-1 != p[t[i]])
            k++;

    printf("%d %d", b, k);

    return 0;
}

