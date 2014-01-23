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

