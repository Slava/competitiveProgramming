#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n, a[5], A[20], B[20], Ans[20], was[20];
int v[20][5], ai, bi, stand[10], ans, u[20];
string s;

bool check ()
{
    bool f = 1;
    memset(stand, 0, sizeof stand);
    memset(was, 0, sizeof was);
    for (int j = 0; j < 4; j++)
        stand[a[j]] = j, was[a[j]] = 1;
    for (int j = 0; j < n; j++)
    {
        ai = bi = 0;
        for (int i = 0; i < 4; i++)
            if (was[v[j][i]])
                if (stand[v[j][i]] == i)
                    ai++;
                else bi++;
        if (ai == A[j] && bi == B[j])
            f &= 1;
        else f &= 0;
    }
    return f;
}

void F (int i, int k)
{
    a[i] = k;u[k] = 1;
    if (i == 3)
    {
        if(check())
        {
            ans++;
            if (ans > 1)
            {
                cout <<"Need more data\n";
                exit(0);
            }
            for (int j = 0; j < 4; j++)
                Ans[j] = a[j];
        }
        u[k] = 0;
//        cout<<"pos: ";
//        for (int j = 0; j < 4; j++)
//            cout << a[j] ;cout <<"\n";
        return;
    }
    for (int j = 0; j < 10; j++)
        if (!u[j])
            F (i + 1, j);
    u[k] = 0;
}

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> A[i] >> B[i];
        for (int j = 0; j < s.size(); j++)
            v[i][j] = s[j] - '0';
    }
    for (int i = 0; i < 10; i++)
        F(0,i);
    if (!ans)
        cout << "Incorrect data\n";
    else
        for (int j = 0; j < 4; j++)
            cout << Ans[j];
    return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 28, 2011 7:50:15 PM
// contest: 63
// link: /contest/63/submission/311211
// time: 30 ms
// verdict: Accepted
// problem: 63C - Bulls and Cows
// ID: 311211
// downloaded by very stupid script
