// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <cstring>
#define abs(a) ((a)<0?-(a):(a))

using namespace std;

char s[55];
long long a[55][10], n, num[55], f = 1, S;

int main ()
{
    cin >> s;
    n = strlen (s);
    for (int i = 0; i < n; i++)
        num[i] = s[i] - '0';
    for (int i = 0; i < 10; i++)
        a[0][i] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < 10; j++)
        {
            long long sum = j + num[i];
            a[i][sum / 2] += a[i - 1][j];
            if (sum & 1)
                a[i][sum / 2 + 1] += a[i - 1][j];
        }

    for (int i = 0; i < 10; i++)
        S += a[n - 1][i];

    for (int i = 1; i < n; i++)
        if (abs(num[i] - num[i - 1]) > 1)
            f = 0;
    S -= f;

    cout << S;

    return 0;
}






// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 3, 2010 6:22:56 AM
// contest: 44
// link: /contest/44/submission/185837
// time: 30 ms
// verdict: Accepted
// problem: 44H - Phone Number
// ID: 185837
// downloaded by very stupid script
