// Kim Vyacheslav KarKTL
#include <cstdio>

using namespace std;

bool check (int a)
{
    bool u[10] = {0};
    for (int i = 0; a; a /= 10)
        if (!u[a%10])
        {
            u[a%10] = 1;
            i++;
            if (i == 3)
                return 0;
        }
    return 1;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n;
    scanf ("%d", &n);

    for (int i = 0; i <= n; i++)
        if (check (n - i))
        {
            printf ("%d", n - i);
            return 0;
        }
        else if (check (n + i))
        {
            printf ("%d", n + i);
            return 0;
        }

    return 0;
}
