#include <iostream>
using namespace std;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long a[200][200],n,m,i=0,j=0,k,p;
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
            if(!i&&j)a[i][j]+=a[i][j-1];
            if(i&&!j)a[i][j]+=a[i-1][j];
            if(i&&j)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(;k>0;k--)
    {
        scanf("%d%d%d%d",&i,&j,&n,&m);
        if(i>n)swap(i,n);
        if(j>m)swap(j,m);
        p=a[n-1][m-1];
        if(j>1)p-=a[n-1][j-2];
        if(i>1)p-=a[i-2][m-1];
        if(i>1&&j>1)p+=a[i-2][j-2];
        cout<<p<<'\n';
    }

    return 0;
}
