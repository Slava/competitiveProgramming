#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vs vector <string>;
vs temp, b;

vector<int>ms, ns;
set <vs>SET;
int n, m, fail;

void add (int si, int fi, int sj, int fj)
{
    string t;
    temp.clear();
    for (int i = si; i < fi; i++){
        for (int j = sj; j < fj; j++)
        {
            t.push_back(b[i][j]);
        }
        temp.push_back(t);
    }
    if (SET.find(temp) == SET.end())
        SET.insert(temp);
    else
    {
        fail = 1;
        return;
    }
    for (int i = )
}
void tryit (int pli, int plj)
{
    a.clear();
    for (int i = 0; i < n - pli; i += pli)
    {
        for (int j = 0; j < m - plj; j += plj)
        {
            add(i, i + pli, j, j + plj);
            if (fail)
                return;
        }
    }
}

int main ()
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        cin  >> b[i];
    for (int i = n; i >= 1; i--)
        if (n % i == 0)
            ns.push_back(i);
    for (int j = m; j >= 1; j--)
        if (m % j == 0)
            ms.push_back(j);
    for (int i = 0; i < ns.size(); i++)
        for (int j = 0; j < ms.size(); j++)
        {
            fail = 0;
            tryit(i, j);
        }
    return 0;
}

