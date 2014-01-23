// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <cstring>


using namespace std;

#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define sz(x) x.size()
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define all(x) (x.begin(),x.end())

long a[60][60];
int n, m, N, M, R = 1000009;

long r (int i, int j, int n, int m)
{
    long p=a[n][m];
    if(j)p-=a[n][j-1];
    if(i)p-=a[i-1][m];
    if(i&&j)p+=a[i-1][j-1];
//    printf ("%d %d %d %d   %ld %ld\n", i, j, n, m, p, a[n][m]);
    return p;
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf ("%ld", &a[i][j]);
            if(!i&&j)a[i][j]+=a[i][j-1];
            if(i&&!j)a[i][j]+=a[i-1][j];
            if(i&&j)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    scanf ("%d%d", &N, &M);
    for (int i = 0; i + N - 1 < n; i++)
        for (int j = 0; j + M - 1 < m; j++)
            R = min (R, r(i,j, i+N-1, j+M-1));

    swap (N, M);
    for (int i = 0; i + N - 1 < n; i++)
        for (int j = 0; j + M - 1 < m; j++)
            R = min (R, r(i,j, i+N-1, j+M-1));
    printf ("%d", R);
    return 0;
}

