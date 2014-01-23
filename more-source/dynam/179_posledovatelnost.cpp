// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[50], s = 1, c, c2;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long n;
    cin >> n;
    // a[i] = a[i - 1] * 3 - 2;
    a[0] = 2;

    for (int i = 0; i < n; i++)
    {
        c = 0;c2 = 0;
        for (int j = 0; j < s || c; j++)
        {
            s = max (s, j + 1);
            a[j] = a[j] * 3 + c - c2;
            if (!j) a[j] -= 2;
            if (a[j] < 0)
            {
                a[j] += 10;
                c2 = 1;
            }
            else c2 = 0;
            c = a[j] / 10;
            a[j] %= 10;
            if (!c && !a[j] && j == s - 1)
                s--;
        }

    }
    for (int i = s - 1; i >= 0; i--)
        cout << a[i];

    return 0;
}

