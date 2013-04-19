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




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 26, 2010 8:08:59 AM
// contest: 41
// link: /contest/41/submission/190614
// time: 30 ms
// verdict: Accepted
// problem: 41C - Email address
// ID: 190614
// downloaded by very stupid script
