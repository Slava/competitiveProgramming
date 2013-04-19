// Kim Vyacheslav KarKTL
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m, k, a[200][200], x1,  x2, y1, y2;
int d[] = {-1, 0, 0, -1, 1, 0, 0, 1, 0, 0};

void out ()
{
    cout << k << '\n';
    if (k)
        cout << x2 << ' ' << y2 << ' '<< x1 << ' '<< y1 << '\n';


    int cx, cy, dx, dy;
    cx = cy = 1;
    cout << "1 1\n";
    dx = d[a[cx][cy]*2];
    dy = d[a[cx][cy]*2 + 1];
    while (true)
    {
        cx += dx; cy += dy;
        if (cx == 1 && cy == 1) {break;}
        cout << cx << ' ' << cy << '\n';
        if (a[cx][cy] == 4) break;
        dx = d[a[cx][cy]*2];
        dy = d[a[cx][cy]*2 + 1];
    }
    cout << "1 1\n";
    exit(0);
}

int main ()
{
    cin >> n >> m;
    if (n == 2 && m == 2)
    {
        cout << "0\n1 1\n2 1\n2 2\n1 2\n1 1\n";
        return 0;
    }
    if (n == 1 && m == 2)
    {
        cout << "0\n1 1\n1 2\n1 1\n";
        return 0;
    }
    if (n == 2 && m == 1)
    {
        cout << "0\n1 1\n2 1\n1 1\n";
        return 0;
    }
    if (n == 1 || m == 1)
    {
        k = 1;
        x1 = y1 = 1;
        x2 = n; y2 = m;
        cout << "1\n" << n << ' ' << m << " 1 1\n";
        if (n == 1)
        {
            for (int i = 1; i <= m; i++)
                cout << 1 << ' ' << i << '\n';
            cout << "1 1\n";
        }
        else
        {
            for (int i = 1; i <= n; i++)
                cout << i << ' ' << 1 << '\n';
            cout << "1 1\n";
        }
        return 0;
    }

    if ((n%2==1) && (m%2==1))
    {
        k = 1;
        x1 = y1 = 1;
        x2 = n; y2 = m;
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
                a[i][j] = (j%2==1?2:0);

            if (j%2==1)
                a[n][j] = 3;
            else
                a[1][j] = 3;
        }
        a[n][m] = 4;
        out();
    }

    if (n%2 == 1 && m%2 == 0)
    {
        k = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i][1] = 2;
            a[i][m] = 0;
        }
        a[n][1] = 3;
        for (int j = 2; j <= m; j++)
            a[1][j] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 2; j < m; j++)
                a[i][j] = (j%2==1?2:0);
        for (int j = 1; j <= m; j += 2)
            a[n][j] = 3;
        for (int j = 2; j < m; j += 2)
            a[2][j] = 3;
        out();
    }
    if (n%2 == 0 && m%2 == 1)
    {
        k = 0;
        for (int i = 1; i <= n; i++)
            a[i][1] = 2;
        for (int i = 1; i <= n; i++)
            for (int j = 2; j <= m; j++)
                a[i][j] = (i%2==1?1:3);
        for (int i = 2; i < n; i++)
            a[i][2] = (i%2==1?0:3);
        for (int i = 1; i <= n; i++)
            a[i][m] = (i%2==1?1:0);
        a[n][1] = 3;
        out();
    }
    if (n%2 == 0 && m % 2 == 0)
    {
        for (int j = 1; j <= m; j += 2)
            for (int i = 1; i <= n; i++)
                a[i][j] = 2;
        for (int j = 2; j <= m; j += 2)
            for (int i = 1; i <= n; i++)
                a[i][j] = 0;
        for (int j = 2; j < m; j++)
            if (j%2==0)a[2][j] = 3;
        for (int j = 1; j < m; j++)
            if (j%2==1)a[n][j] = 3;
        for (int j = 2; j <= m; j++)
            a[1][j] = 1;
        out();
    }

    return 0;
}





// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Nov 30, 2010 5:46:55 AM
// contest: 43
// link: /contest/43/submission/204703
// time: 50 ms
// verdict: Accepted
// problem: 43D - Journey
// ID: 204703
// downloaded by very stupid script
