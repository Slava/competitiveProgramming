// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, i, a, s1, s2;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &a);
        a++;
        s1 = a / 100000 + (a / 10000) % 10 + (a / 1000) % 10;
        s2 = (a / 100) % 10 + (a / 10) % 10 + a % 10;
        if (s1 == s2)
        {
            puts ("Yes");
            continue;
        }
        a -= 2;
        s1 = a / 100000 + (a / 10000) % 10 + (a / 1000) % 10;
        s2 = (a / 100) % 10 + (a / 10) % 10 + a % 10;
        if (s1 == s2)
        {
            puts ("Yes");
            continue;
        }
        puts ("No");
    }

    return 0;
}

