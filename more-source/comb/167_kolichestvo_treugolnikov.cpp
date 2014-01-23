#include <iostream>

using namespace std;

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    __int64 r = 0, n, i, p = 0, k = 0;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        p++;
        k += p;
        r += k;
    }
    if(n>1)r++;
    if(n>2)r += 2;
    p = 1;
    k = 2;
    for(i = 4; i <= n; i++)
    {
        if(i%2==0)p++;
        k += p;
        r += k;
    }

    cout << r;

    return 0;
}
