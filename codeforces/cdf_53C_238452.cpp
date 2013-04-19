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





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 6, 2011 7:24:31 PM
// contest: 53
// link: /contest/53/submission/238452
// time: 30 ms
// verdict: Accepted
// problem: 53C - Little Frog
// ID: 238452
// downloaded by very stupid script
