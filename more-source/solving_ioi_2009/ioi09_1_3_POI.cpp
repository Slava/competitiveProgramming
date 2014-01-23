//ioi2009 review
//solution by Kim Vyacheslav
#include <cstdio>
#include <algorithm>

using namespace std;

#define DEBUG
#define MAXN 2001

bool a[MAXN][MAXN];
int p, n, t, solved[MAXN], unsolved[MAXN];
pair<int, pair<int, int> >b[MAXN];

void load()
{
    scanf("%d %d %d", &n, &t, &p);
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < t; j++)
            scanf("%d", &a[i][j]);
    
}

void solve()
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < t; j++)
        {
            unsolved[j] += !a[i][j];
            solved[i] += a[i][j];
        }
    }
    for(i = 0; i < n; i++)
    {
        int p = 0;
        for(j = 0; j < t; j++)
            p += a[i][j] * unsolved[j];
    b[i] = make_pair(p, make_pair(solved[i], i+1));
    }
    
    sort(b, b+n);
    for(i = 0; i < n; i++)
        if(b[i].second.second == p)
        {
            printf("%d %d", b[i].first, b[i].second.first);
            break;
        }
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    load();
    solve();
    
    return 0;
}

