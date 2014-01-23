// Sitmuhambetov Satjan
#include <iostream>
#include <string>

using namespace std;
long long n, a[99] = {0, 2, 4, 7}, i;
int main () {
    cin >> n;
    for (i = 4; i <= n; i++)
        a[i] = a[i - 1] +
               a[i - 2] +
               a[i - 3];
    cout <<a[n];
}