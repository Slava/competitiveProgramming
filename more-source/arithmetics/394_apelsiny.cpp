// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>

using namespace std;

__int64 n, m;

__int64 nod (__int64 a, __int64 b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else b %= a;
    }
    return a + b;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> n >> m;
    cout << n*m/nod(n,m)/m;

    return 0;
}
