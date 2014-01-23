#include <cstdio>
#include <iostream>

using namespace std;

int main ()
{
    int n, l, r;
    l = 1;
    cin >> n;

    r = n;
    while (l <= r)
    {
        cout << l << " ";
        l++;
        if (l <= r)
        cout << r << " ";
        r--;
    }

    return 0;
}

