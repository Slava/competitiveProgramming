// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char s[10];
    scanf ("%s", s);
    int n = strlen (s), p = 0, x1, x2, y1, y2,
        d[] = {1, 2, 2, 1, -1, 2, 2, -1, 1, -2, -2, 1, -1, -2, -2, -1};
    if (n != 5 || s[2] != '-' || s[0] < 'A' || s[0] > 'H'
        || s[3] < 'A' || s[3] > 'H' || s[1] < '1' || s[1] > '8' || s[4] < '1' || s[4] > '8')
        {puts("ERROR");return 0;}
    x1 = s[0] - 'A';
    x2 = s[3] - 'A';
    y1 = s[1] - '0';
    y2 = s[4] - '0';

    for (int i = 0; i < 16; i += 2)
        if (x1 + d[i] == x2 && y1 + d[i + 1] == y2)
            p = 1;
    puts (p ? "YES" : "NO");

    return 0;
}

