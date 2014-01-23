#include <iostream>

using namespace std;

int a[109][109][109],A[109],B[109],C[109],na,nb,nc;
long i,j,k;
int main()
{
    cin>>na;
    for(i=1;i<=na;i++)
        cin>>A[i];
    cin>>nb;
    for(i=1;i<=nb;i++)
        cin>>B[i];
    cin>>nc;
    for(i=1;i<=nc;i++)
        cin>>C[i];

    for(i=1;i<=na;i++)
        for(j=1;j<=nb;j++)
            for(k=1;k<=nc;k++)
                a[i][j][k] = (a[i][j-1][k-1]||a[i-1][j][k-1]||a[i-1][j-1][k]) + (A[i]==B[j]&&B[j]==C[k]);
    cout<<a[na][nb][nc]<<endl;
    while(a[na][nb][nc])
    {
        if(A[na]==B[nb]&&B[nb]==C[nc]){cout<<A[na]<<' ';}

            if(a[na-1][nb][nc]==a[na][nb][nc])na--;else
            if(a[na][nb-1][nc]==a[na][nb][nc])nb--;else
            if(a[na][nb][nc-1]==a[na][nb][nc])nc--;
        if(!a[na][nb][nc])break;
    }

}
