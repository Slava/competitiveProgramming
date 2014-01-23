/*
ID: imslavko1
PROG: dishes
LANG: C++
*/

#include <cstdio>
#include <stack>

using namespace std;

stack <int> a[3];
int n, cmd, d;

int main ()
{
    freopen ("dishes.in", "r", stdin);
    freopen ("dishes.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = n; i; i--)
        a[0].push(i);
    while (a[1].size() || a[0].size())
    {
        scanf ("%d%d", &cmd, &d);
        for (int i = 0; i < d; i++)
        {
            a[cmd].push(a[cmd - 1].top());
            a[cmd - 1].pop();
        }
    }

    while (a[2].size())
    {
        printf ("%d\n", a[2].top());
        a[2].pop();
    }

    return 0;
}

