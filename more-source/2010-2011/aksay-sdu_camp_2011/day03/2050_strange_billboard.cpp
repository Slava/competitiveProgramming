#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int n, m, ans, sum;
char s[20];
vector<int>a, b, mask(1 << 17), number(1 << 17);

void sh(int x)
{
    for (int i = 0; i < m; i++, x /= 2)
        cout << x % 2;
    cout << "\n";
}

void count ()
{
    int maxmask = (1 << m) - 1;
    for (int i = 0; i < (1 << m); i++)
    {
        int msk = 0;
        for (int j = 1; j < (1 << m); j <<= 1)
            if (j & i)
            {
                number[i]++;
                msk ^= j;
                msk ^= (j >> 1);
                msk ^= (j << 1);
            }
        mask[i] = msk & maxmask;
    }
}

void solve ()
{
    a.clear();
    b.clear();
    mask.clear();
    number.clear();
    a.resize(n,0);
    b.resize(n,0);
    mask.resize(1 << m,0);
    number.resize(1 << m,0);
    sum = 7777777;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i] |= ((s[j] == 'X') << j);
    }
    count();
    b = a;

    if (a.size() == 1)
        for (int msk = 0; msk < (1 << m); msk++)
        {
            a[0] ^= mask[msk];
            if (!a[0])
                sum = min(sum, number[msk]);
            a = b;
        }

    else
    for (int msk = 0; msk < (1 << m); msk++)
    {
        ans = number[msk];
        a[0] ^= mask[msk];
        a[1] ^= msk;

        for (int i = 1; i < n - 1; i++)
        {
            a[i] ^= mask[a[i - 1]];
            a[i + 1] ^= a[i - 1];
            ans += number[a[i - 1]];
        }
        ans += number[a[n - 2]];

        a[n - 1] ^= mask[a[n - 2]];
        if (!a[n - 1])
            sum = min (sum, ans);


        a = b;
    }

    if (sum != 7777777)
        cout << "You have to tap " << sum << " tiles.\n";
    else cout << "Damaged billboard.\n";

}

int main ()
{
    while(cin >> n >> m)
        if (n && m)
            solve();

    return 0;
}


