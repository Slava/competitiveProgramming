#include <cstdio>
#include <iostream>

using namespace std;

int n, k, a[200], x, ans;
int main ()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;a[x]++;
    }
    for (ans = 0;;ans++)
    {
        int was = 0;
        for (int i = k - 1; i; i--)
            if (a[i])
                a[i]--, a[i+1]++, was = 1;
        if (!was)
            break;
    }
    cout << ans;
    return 0;
}
