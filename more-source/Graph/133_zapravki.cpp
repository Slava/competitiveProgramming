#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int a[10001][3],d[10001],k,n,m,i,j,l=30000;
    cin>>n;
    for(i=1;i<=n;i++)cin>>d[i];
    cin>>m;
    for(i=1;i<=m*2;i+=2)
    {
        cin>>a[i][0]>>a[i][1];a[i][2]=d[a[i][0]];
        a[i+1][0]=a[i][1];a[i+1][1]=a[i][0];a[i+1][2]=d[a[i][1]];
    }

    d[1]=0;
    for(i=2;i<=n;i++)d[i]=l;

    for(j=1;j<n;j++)
        for(i=1;i<=m*2;i++)
            d[a[i][1]] = min( d[a[i][1]], d[a[i][0]] + a[i][2] );

    if(d[n]==l)cout<<"-1";else
    cout<<d[n];

    return 0;
}
