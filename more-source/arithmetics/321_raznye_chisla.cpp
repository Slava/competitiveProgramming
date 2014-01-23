// Kim Vyacheslav KarKTL
#include <cstdio>
#include <vector>

using namespace std;

vector <long> u(40);

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n;
    scanf ("%ld", &n);

    for (int i = 2; i <= 36; i++)
    {
        bool t = 1;
        u.assign (40, 0);
        for (long b = n; b; b /= i)
            u[b%i]++;
        for (int j = 0; j < 40; j++)
            if (u[j] > 1){t = 0; break;}
        if (t)
            printf ("%d ", i);
    }

    return 0;
}
