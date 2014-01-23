#include <iostream>

using namespace std;

long long a[50] = {0, 1, 2};

int main ()
{
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2];
    cout << a[n];
}