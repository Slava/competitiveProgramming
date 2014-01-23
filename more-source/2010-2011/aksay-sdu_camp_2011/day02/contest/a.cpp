#include <cstdio>
#include <iostream>

using namespace std;

long n, i;
long long layer = 1, ans;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        ans += layer * 2;
        layer += i*4;
    }
    ans += layer;
    cout << ans;

    return 0;
}

