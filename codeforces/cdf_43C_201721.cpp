// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>

using namespace std;

#define min(a,b) (a<b?a:b)

long A[4], a[10009], n;

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        A[a[i]%3]++;
    }
    cout << min (A[1], A[2]) + A[0] / 2;

    return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Nov 29, 2010 7:18:57 PM
// contest: 43
// link: /contest/43/submission/201721
// time: 50 ms
// verdict: Accepted
// problem: 43C - Lucky Tickets
// ID: 201721
// downloaded by very stupid script
