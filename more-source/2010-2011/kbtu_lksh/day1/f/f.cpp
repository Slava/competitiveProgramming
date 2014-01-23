#define file "floyd"
#include <cstdio>
#include <iostream>

using namespace std;

long long n, a[200][200];
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " \n"[j == n - 1];

    return 0;
}
