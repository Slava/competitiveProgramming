// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <set>

using namespace std;

#define file "headshot"

char c;
int a[200], n, b[2];

int main ()
{
    freopen (file".in", "r", stdin);
    freopen (file".out", "w", stdout);


    while (cin >> c)
        a[n++] = c - '0';
    for (int i = 1; i < n; i++)
        if (!a[i - 1]) b[a[i]]++;
    if (!a[n - 1]) b[a[0]]++;
    if (!b[1]) puts("EQUAL"); else
    if (b[0] == b[1]) puts("EQUAL"); else
    if (b[0] > b[1]) puts("SHOOT"); else
    if (b[0] < b[1]) puts("ROTATE");

    return 0;
}
