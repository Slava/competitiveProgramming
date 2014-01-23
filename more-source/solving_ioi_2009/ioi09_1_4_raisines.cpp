//ioi 2009 review
//solution by Kim Vyacheslav
#include <iostream>
#include <cstdio>

using namespace std;

#define i64 __int64
#define MAXN 60
#define MAXLONG 1000000000
//#define DEBUG

i64 a[MAXN][MAXN], b[MAXN][MAXN], n, m, ans,
    M[MAXN][MAXN][MAXN][MAXN];

void inputdata()
{
    scanf("%lld %lld", &n, &m);
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%lld", &a[i][j]);
}

void sumtable()
{
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            b[i][j] = a[i][j] + (i?b[i-1][j]:0) + (j?b[i][j-1]:0) - (i&&j?b[i-1][j-1]:0);
            
    #ifdef DEBUG
    cout << "\n==DEBUG b== \n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }
    cout << "\n==DEBUG b== \n";
    #endif
}

i64 B(int i, int j, int n, int m)
{
    i64 p=b[n][m];
    if(j)p-=b[n][j-1];
    if(i)p-=b[i-1][m];
    if(i&&j)p+=b[i-1][j-1];
    return p;
}

i64 S(int si, int fi, int sj, int fj)
{
    if(si==fi&&sj==fj)return 0;
    
    i64 s = MAXLONG, r = B(si,sj,fi,fj);
    int i, j;
    for(i = si + 1; i <= fi; i++)
    {
        if(!M[i][fi][sj][fj])
            M[i][fi][sj][fj] = S(i, fi, sj, fj);
        if(!M[si][i-1][sj][fj])
            M[si][i-1][sj][fj] = S(si, i-1, sj, fj);
        s = min(s, M[i][fi][sj][fj] + M[si][i-1][sj][fj]);
    }
    for(j = sj + 1; j <= fj; j++)
    {
        if(!M[si][fi][j][fj])
            M[si][fi][j][fj] = S(si, fi, j, fj);
        if(!M[si][fi][sj][j-1])
            M[si][fi][sj][j-1] = S(si, fi, sj, j-1);
        s = min(s, M[si][fi][j][fj] + M[si][fi][sj][j-1]);
    }
    
    #ifdef DEBUG
    cout << "\ndebug\n" << si << ' ' << sj << ' ' << fi << ' ' << fj << endl<<  r << ' ' << s << "\ndebug\n";
    #endif
    
    return s+r;
}

void solve()
{
    ans = S(0,n-1,0,m-1);
    printf("%lld", ans);
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    inputdata();
    sumtable();
    solve();
    
    return 0;
}

