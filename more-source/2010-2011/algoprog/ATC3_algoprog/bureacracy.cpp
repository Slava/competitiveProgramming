#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
bool a[100009];
bool u[100009];

vector <int>p[100009];

bool Tr (int i)
{
    u[i] = 1;
    if (p[i].empty()){a[i] = 1; return 1;};
    for (int j = 0; j < p[i].size(); j++)
    {
        if (Tr(p[i][j])){a[i] = 0; return 0;}
    }
    a[i] = 1;
    return 1;
}

main ()
{
    freopen ("bureau.in", "r", stdin);
    freopen ("bureau.out", "w", stdout);

    char s[1000];

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (s[0] == 'd')
        {
            a[i] = 1;
        }
        else
        {
            int T;
            cin >> T;
            p[T].push_back(i);
            a[i] = 1;
        }

    }
    vector<int> ans;
    for (int i = 1; i <=n; i++)
    {
        if (!u[i])Tr(i);
        if (a[i])ans.push_back(i);
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i]<< " ";

    return 0;
}

