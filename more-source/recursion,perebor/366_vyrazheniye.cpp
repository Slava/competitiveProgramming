// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <stack>

using namespace std;

int n, k, a[30];
stack<int> s;

bool p (int i, int x)
{
    if (i == n + 1)
    {
        if (x == k) return 1;
        return 0;
    }
    if (p (i + 1, x + a[i]))
    {
        s.push (a[i]);
        return 1;
    }
    if (p (i + 1, x - a[i]))
    {
        s.push (-a[i]);
        return 1;
    }
    return 0;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    if (!p (1, a[0]))
        printf ("No solution");
    else
    {
        printf ("%d", a[0]);
        while (s.size() > 1)
        {
            printf ("%+d", s.top());
            s.pop();
        }
        printf ("=%d", k);
    }

    return 0;
}

