#include <iostream>
#include <string>

using namespace std;
int a[109][109], i, j, s, n;
int main () {
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    for (s = 0, i = 1; i <= n; i++)
        s += a[i][i];
    cout << s << " ";
    for (s = 0, i = 1; i <= n; i++)
        s += a[i][n + 1 - i];
    cout << s;
} 
