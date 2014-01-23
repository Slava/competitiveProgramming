#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);

    char s[50000];
    int cur = 0;
    bool r;

    for (int i = 0; cin >> s; i++)
    {
        int n;
        r = 0;
        n = strlen (s);
        if (!n)break;
        for (int j = 0; j < n; j++)
        {
            if ((int)s[j] == (int)('a' + i))
            {
                r = 1; break;
            }
        }
        cur = (!cur);
        if (!r)
        {
            printf ("PLAYER %d", cur+1);
            goto end;
        }

    }

    puts ("NO WINNER");
end:
    return 0;
}

