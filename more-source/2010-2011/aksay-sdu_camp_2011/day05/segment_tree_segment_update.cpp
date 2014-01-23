#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


vector<long> a, t, v;
long n, hz = -123456789;

void build (int i = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        t[i] = a[l];
        v[i] = a[l];
    }
    else
    {
        int m = (l + r) / 2;
        build (i + i, l, m);
        build (i + i + 1, m + 1, r);
        t[i] = t[i + i] + t[i + i + 1];
        if (v[i + i] == v[i + i + 1])
            v[i] = v[i + i];
        else v[i] = hz;
    }
#ifdef debug
    cout << "Sum on range [" << l << ", " << r << "] is " << t[i] << "\n";
#endif
}

long sum (int l, int r, int i = 1, int tl = 0, int tr = n - 1)
{
#ifdef debug
    cout << "Entered in [" << tl << ", " << tr
        << "] for sum on range [" << l << ", " << r << "]\n";
#endif
    if (v[i] != hz)
        return v[i] * (r - l + 1);
    if (l == tl && r == tr)
        return t[i];
    int m = (tl + tr) / 2;
    if (l > m)
        return sum (l, r, i + i + 1, m + 1, tr);
    if (r <= m)
        return sum (l, r, i + i, tl, m);
    return sum (l, m, i + i, tl, m) + sum(m + 1, r, i + i + 1, m + 1, tr);
}

void update (int l, int r, int val, int i = 1, int tl = 0, int tr = n - 1)
{
#ifdef debug
    cout << "Entered in [" << tl << ", " << tr
        << "] for updating on range [" << l << ", " << r << "] by value " << val << "\n";
#endif
    if (tl == l && tr == r)
        v[i] = val;
    else
    {
        bool cha, chb;
        cha = chb = 0;
        int m = (tl + tr) / 2;
        if (l > m)
        {
            update (l, r, val, i + i + 1, m + 1, tr);
            chb = 1;
        }
        else if (r <= m)
        {
            update (l, r, val, i + i, tl, m);
            cha = 1;
        }
        else
        {
            update (l, m, val, i + i, tl, m);
            update (m + 1, r, val, i + i + 1, m + 1, tr);
            cha = chb = 1;
        }
        if (v[i] != hz)
        {
            t[i] = 0;
            if (cha)
                t[i] += sum(tl, m, i + i, tl, m);
            else
                t[i] += v[i] * (m - tl + 1);
            if (chb)
                t[i] += sum (m + 1, tr, i + i + 1, m + 1, tr);
            else t[i] += v[i] * (tr - m);
        }
        else t[i] = sum(tl, m, i + i, tl, m) + sum (m + 1, tr, i + i + 1, m + 1, tr);
        if (v[i + i] == v[i + i + 1])
            v[i] = v[i + i];
        else v[i] = hz;
#ifdef debug
        cout << "Updated in range [" << tl << ", " << tr << "] and sum is " << t[i] << " v[i]="<<v[i]<<"\n";
#endif
    }
}

int main ()
{
    int m;
    scanf ("%d", &n);
    a.resize(n);
    t.resize(4 * n);
    v.resize(4 * n);

    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);

    build();
    scanf ("%d", &m);

    int l, r, val;
    char cmd;
    while (m--)
    {
        cin >> cmd;
        scanf ("%d%d", &l, &r);
        if (cmd == 's')
            printf ("%d\n", sum(l - 1, r - 1));
        else
        {
            scanf ("%d", &val);
            update (l - 1, r - 1, val);
        }

    }

    return 0;
}

