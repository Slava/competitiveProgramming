// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>

using namespace std;

__int64 res[2000009], sum[1000009], constant = 1000001, n;
char s[1000009];

__int64 ans;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    cin >> n >> s;
    sum[0] = (s[0] == 'a' ? 1 : -1);
    for (int i = 1; i < n; i++)
        if (s[i] == 'a')
            sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;
    for (int i = 0; i < n; i++)
        res[sum[i] + constant]++;

    for (int i = 0; i < 2000009; i++)
        if (res[i])
            ans += (__int64)(res[i] * (res[i] - 1) / 2);

    cout << (__int64)(ans + res[constant]);

    return 0;
}

