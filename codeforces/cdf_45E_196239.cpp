// Kim Vyacheslav KarKTL
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string name[109], sur[109];
int n, ncount[256], scount[256], with[109], k;
bool u[109];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
        ncount[name[i][0]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> sur[i];
        scount[sur[i][0]]++;
    }
    sort (name, name + n);
    sort (sur, sur + n);

    for (int i = 0; i < n; i++)
    {
        for (k = 0; k < n; k++)
            if (!u[k] && (name[i][0] == sur[k][0] || scount[sur[k][0]] > ncount[sur[k][0]]))
                if (name[i][0] == sur[k][0] || scount[name[i][0]] < ncount[name[i][0]])break;
        with[i] = k;
        u[k] = true;
        scount[sur[k][0]]--;
        ncount[name[i][0]]--;
    }

    for (int i = 0; i < n; i++)
    {
        if (i) printf(", ");
        cout << name[i] << " " << sur[with[i]];
    }

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 26, 2010 7:09:47 AM
// contest: 45
// link: /contest/45/submission/196239
// time: 30 ms
// verdict: Accepted
// problem: 45E - Director
// ID: 196239
// downloaded by very stupid script
