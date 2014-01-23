// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, m, s, tt;
    string t;
    set< pair<int, string> > S;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        s = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> tt;
            s += tt;
        }
        S.insert (make_pair(s, t));
    }
    cout << S.begin()->second;

    return 0;
}
