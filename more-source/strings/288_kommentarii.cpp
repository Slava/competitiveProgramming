// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char s[2000000];
    int n, ans = 0, mode = 0;
    // modes : 0 normal, 1 'mode, 2 {}mode, 3 (**)mode
    while (gets(s))
    {
        n = strlen (s);
        for (int i = 0; i < n; i++)
        {
            if (!mode && s[i] == '\'')
            {
                mode = 1;continue;
            }
            if (mode == 1 && s[i] == '\'')
            {
                mode = 0;continue;
            }

            if (!mode && s[i] == '{')
            {
                mode = 2;continue;
            }
            if (mode == 2 && s[i] == '}')
            {
                mode = 0;ans++;
                continue;
            }

            if (!mode && s[i] == '(' && i != n-1 && s[i+1] == '*')
            {
                mode = 3;continue;
            }
            if (mode == 3 && s[i] == '*' && i != n-1 && s[i+1] == ')')
            {
                mode = 0;
                ans++;continue;
            }

            if (!mode && s[i] == '/' && i != n-1 && s[i+1] == '/')
                {ans++;break;}
        }
    }

    printf ("%d", ans);

    return 0;
}
