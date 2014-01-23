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
