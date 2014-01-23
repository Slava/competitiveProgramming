#include <cstdio>
#include <iostream>

using namespace std;

long long n, last_divisor = -1, i = 3;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> n;
    while (n % 2 == 0)
    {
        last_divisor = 2;
        n /= 2;
    }
    for (; i <= n; i += 2)
        while (n % i == 0)
        {
            n /= i;
            if (last_divisor == -1)
                last_divisor = i;
            if (last_divisor != i)
            {
                cout << 1;
                return 0;
            }
        }
    if (last_divisor == -1)
        cout << n;
    else cout << last_divisor;

    return 0;
}

