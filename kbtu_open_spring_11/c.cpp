#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int i, j;
//
#define __int64 long long
#define mod 1000000007
class T
{
    public:
    long long a[7][7];
    T()
    {
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
                a[i][j] = 0;
    }


};

void print(T a)
{
    int i, j;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            cout << setw(5) << a.a[i][j];
        }
        cout << endl;
    }
}
T mul(T x, T y)
{
    T res;
    int i, j, k;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            for (k = 0; k < 7; k++)
            {
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % mod) % mod;
            }
        }
    }


    return res;
}
T bin_pow(T a, int n)
{
    T res = a;
    while (n > 0)
    {
        if (n & 1) res = mul(res, a), n--;
        n >>= 1;
        a = mul(a, a);
    }
    return res;
}
__int64 n, a[100009], b[100009];
main ()
{
    freopen ("bernoulli.in", "r", stdin);
    freopen ("bernoulli.out", "w", stdout);
    T a;
    cin >> n;
    a.a[1][0] = 1;

    for (i = 0; i < 7; i++)
    {
        a.a[i][i] = 1;
        a.a[6][i] = 1;
    }

    a.a[2][0] = a.a[2][1] = a.a[5][0] = a.a[5][1] = 5;
    a.a[3][0] = a.a[3][1] = a.a[4][0] = a.a[4][1] = 10;
    a.a[3][2] = a.a[5][2] = 4;
    a.a[4][2] = 6;
    a.a[4][3] = a.a[5][3] = 3;
    a.a[5][4] = 2;
    long long res = 0;
    for (i = 1; i <= 5; i++)
    {
        res += pow(i, 5);
    }

    if (n < 6)
    {
        res = 0;
        for (i = 1; i <= n; i++)
        {
            res += pow(i, 5);
        }
        cout << res << endl;
    }
    else
    {
        n -= 5;
        a = bin_pow(a, n - 1);
//        print(a);
        long long ans = 0, j = 1;
        for (i = 6; i > 0; i--, j *= 5)
        {
            ans = (ans + j * a.a[i][0] % mod) % mod;
        }
        cout << (ans + res) % mod;
    }
}
