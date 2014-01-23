// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

bool check (int a)
{
    int sum = 0, n = 0;
    for (;a; a /= 10) sum += a%10, n++;
    if (sum%n == 0)return 1;
    return 0;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, a = 1;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++, a++)
        while (!check(a)) a++;
    printf ("%d", --a);

    return 0;
}
