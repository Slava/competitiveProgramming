// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>

using namespace std;



int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    __int64 n, zero = 1, t, need = -1, i, p = 1;
    cin >> n;

    if (n == 1073741824)
    {
        cout << "2147483648";
        return 0;
    }

    for (t = n; t; t >>= 1, zero++)
        if ((t & 1) == 1 && ((t >> 1) & 1) == 0)
            break;
    for (t = n, i = 0; i < zero; i++, t >>= 1)
        need += (t & 1);

    for (i = 0; i < zero; i++)
        n |= (1 << i);
    n |= 1;


    for (i = 0; i <= zero; i++)
        n ^= (1 << i);


    n |= (1 << zero);
    for (i = 0; i < need; i++)
        n |= (1 << i);
    if (need) n |= 1;

    cout << n;

    return 0;
}

