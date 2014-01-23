#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class matrix
{
    public:
        T a[100][100];
        int n, m;
        matrix () {n = m = 0;}
        matrix (int _n, int _m = 0, bool zero = 0)
        {
            n = _n;
            if (!_m) _m = _n;
            m = _m;
            memset(a, 0, sizeof(a));
            if (zero)
            for (int i = 0; i < min(n,m); i++)
                a[i][i] = 1;
        }
        matrix<T> operator * (matrix<T> &b)
        {
            matrix<T> c(n,b.m);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < b.m; j++)
                    for (int k = 0; k < m; k++)
                        c.a[i][j] += a[i][k] * b.a[k][j];
            return c;
        }
};

template <class T>
matrix<T> operator ^ (matrix<T> &a, int n)
{
    matrix<T> res = a; n--;
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    matrix<int> a(2), f(1,2);
    a.a[0][1] = a.a[1][0] = a.a[1][1] = 1;
    f.a[0][1] = 1;f.a[0][0] = 0;
    int n; cin >> n;
    if (n < 2)
    {
        cout << n;
        return 0;
    }
    n--;
    a = a ^ n;
    f = f * a;
    cout << f.a[0][1];

    return 0;
}

