// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    long long n, a = 1, i, j;
	cin >> n;
    for (i = 2; i <= n; i++)
    {
        j = i;
        a *= j;
        while (a%10 == 0) a /= 10;
        a %= 1000000;
    }

	cout << a % 10;

    return 0;
}
