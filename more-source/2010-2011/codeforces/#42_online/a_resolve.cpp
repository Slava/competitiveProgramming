// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);

    string a, b, t;
    int n, f = 0, a1 = 0, a2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (!f)
        {
            a = t;
            f = 1;
            a1++;
        }
        else if (t == a)
        {
            a1++;
        }
        else
        {
            b = t;
            a2++;
        }
    }

    if (a1 > a2)
        cout << a;
    else cout << b;

    return 0;
}
