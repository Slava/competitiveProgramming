#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

short a[7000][7000];
int n, K, ans, l, r;
string s;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> n >> K >> s;

    ans += n;
    for (int plus = 1; plus <= n; plus++)
    {
        for (int l = 0; l < n; l++)
        {
            if (l + plus >= n)
                break;
            r = l + plus;
            a[l][r] = (s[l] != s[r]);
            if (l + 1 <= r - 1)
                a[l][r] += a[l + 1][r - 1];
            if (a[l][r] <= K)
                ans++;
        }
    }

    cout << ans;

    return 0;
}
