// Kim Vyacheslav KarKTL
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

__int64 a, i;
vector <__int64>diviser;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> a;
    for (i = 2; i * i <= a; i++)
        while (a % i == 0)
        {
            diviser.push_back (i);
            a /= i;
        }
    if (a != 1) diviser.push_back(a);

    cout << diviser[0] ;
    for (i = 1; i < diviser.size(); i++)
        cout << '*' << diviser[i];

    return 0;
}
