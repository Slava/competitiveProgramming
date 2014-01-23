// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <set>

using namespace std;

#define file "database"

string database[10009][20];
int n, m;
char S[10000];

int main ()
{
    freopen (file".in", "r", stdin);
    freopen (file".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++){
            cin.getline(S, 10000, ',');
            string s(S);
            database[i][j] = s;
        }
        cin.getline(S, 10000, '\n');
        string t(S);
        database[i][m - 1] = t;
    }
/*
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i != j && (database[i][i] == database[j][i]
                || database[j][j] == database[i][j]))
            {
                puts ("NO");
                printf ("%d %d\n%d %d\n",i + 1,j + 1,i + 1,j + 1);
                return 0;
            }
*/
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = 0; k < m; k++)
                if (database[i][k] == database[j][k])
                {
                    printf ("NO\n%d %d\n%d %d\n", i + 1, j + 1, i + 1, j + 1);
                    return 0;
                }

    puts ("YES");

    return 0;
}
