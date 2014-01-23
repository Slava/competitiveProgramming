#include <cstdio>
using namespace std;

int n, s, r, m;
int a[200][200], d[200],
    i, j, u[200];

int main (){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf ("%d%d%d", &n,&s,&r);

    for( i = 1; i <= n; i++){
        for( j = 1;j <= n; j++)
        {    scanf ("%d", &a[i][j]);
            if (a[i][j] < 0)
                a[i][j] = 15000;
        }
        d[i] = 15000;
    }

    d[0] = 15001;
    d[s] = 0;
    for( i = 1; i <= n; i++){
        m = 0;
        for( j = 1; j <= n; j++)
            if (d[j] < d[m] && !u[j])
                m = j;
        u[m] = 1;
        for(j = 1; j <= n; j++)
            if (d[j] > a[m][j] + d[m])
                d[j] = a[m][j] + d[m];
    }
    if (d[r] == 15000)
        puts("-1";
    else
        printf ("%d", d[r]);

    return 0;
}
