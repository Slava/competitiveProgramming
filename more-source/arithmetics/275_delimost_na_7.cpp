// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, ans = 0, a[] = {1, 2, 4};
    char s[1009];
    scanf ("%d", &n);

    for (int i = 0; i < n; i++)
    {
        ans = 0;
        scanf ("%s", s);
        for (int j = strlen(s) - 1, k = 0; j >= 0; j--, k++)
            if (s[j] == '1')
                ans += a[k % 3];
        if (ans % 7 == 0)
            puts ("Yes");
        else puts ("No");
    }

    return 0;
}
