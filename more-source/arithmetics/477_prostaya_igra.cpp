// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char s[300];
    long n, sum = 0;
    scanf ("%s", s);
    n = strlen (s);

    for (int i = 0; i < n; i++)
        sum = (sum + s[i] - '0') % 3;
    switch (sum)
    {
        case 0: printf("2");break;
        case 1: printf("1\n1");break;
        default: printf("1\n2");
    }

    return 0;
}
