// Slava Kim 10b KarKTL
//German, privet
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 100001

int n, i, ans;
char s[maxn+1];

int main ()
{
    freopen ("sum.in", "r", stdin);
    freopen ("sum.out", "w", stdout);

    scanf("%s", s);
    n = strlen (s);
    for (int i = 0; i < n; i++)
        ans += (int)(s[i] - '0');
    printf("%d", ans);

    return 0;
}
