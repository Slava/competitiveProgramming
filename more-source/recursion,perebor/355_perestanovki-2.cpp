// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char s[2][9];
    int ans = 0, t = 1, f = 0, n;
    scanf ("%s", s[0]);
    n = strlen (s[0]);
    sort (s[0], s[0] + n);
    strcpy (s[1], s[0]);

    printf ("%s\n", s[f]);
    while (next_permutation (s[f], s[f] + n))
    {
        if (strcmp (s[0], s[1]))
        {
            printf ("%s\n", s[f]);
            strcpy (s[t], s[f]);
            swap (f, t);
        }
    }


    return 0;
}

