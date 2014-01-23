// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    char s[2000], c;
    int n, at = 0;
    scanf ("%s", s);
    n = strlen (s);
    for (int i = 0; i < n; i++)
    {
        c = s[i];
        if (c == 'a' && !at && i && i != n - 2 && s[i + 1] == 't')
        {
            c = '@';at = 1; i++;
        }
        if (c == 'd' && i && i != n - 3 && s[i + 1] == 'o' && s[i + 2] == 't')
        {
            c = '.'; i += 2;
        }

        putchar (c);
    }

    return 0;
}
