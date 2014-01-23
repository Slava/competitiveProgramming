// Sitmuhambetov Satjan KarKTL
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[99];
int a[109][109], i, j, l;
main ()
{
    cin >> s;
    a[1][0] = 1;
    for (l = strlen(s), i = 0; i < l; i++)
        for (j = 1; j < l; j++) {
        if (s[i] == '?')
            a[j][i + 1] = a[j - 1][i] + a[j + 1][i];
        if (s[i] == '(')
            a[j][i + 1] = a[j - 1][i];
        if (s[i] == ')')
            a[j][i + 1] = a[j + 1][i];
        }
    cout << a[1][l];
} 
