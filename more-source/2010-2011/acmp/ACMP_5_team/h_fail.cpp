// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
double i, j, r, l;
int s;
double d(double x, double y) {
    return sqrt(x * x + y * y);
}
int main ()
{
  //  freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
    cin >> r >> l;
    j = r - 1; i = l;
    while (i < r) {
        int x = j;
        j = x;
        while (d(i , j) > r)
            j--;
        s = s +  (j / l);
        i += l;
    }
    cout << s * 4;
}
