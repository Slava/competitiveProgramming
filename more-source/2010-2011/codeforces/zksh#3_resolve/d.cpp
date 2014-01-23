// Kim Vyacheslav KarKTL
#include <cstdio>
#include <algorithm>

using namespace std;

pair<pair<int,int>, int>a[1000];
bool u[10000009];
int n, ans[1000];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d %d", &a[i].first.second, &a[i].first.first);
        a[i].second = i;
    }

    sort (a, a + n);
    for (int i = 0; i < n; i++)
    {
        int t = a[i].first.second;
        while (u[t])
            t++;
        u[t] = 1;
        ans[a[i].second] = t;
    }

    for (int i = 0; i < n; i++)
        printf ("%d ", ans[i]);

    return 0;
}
