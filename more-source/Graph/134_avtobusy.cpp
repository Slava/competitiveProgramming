#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int a[10001][4],d[10001],k,n,m,i,j,l=30000,s,f;
    cin>>n>>s>>f>>m;
    for(i=1;i<=m;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];

    if(s==f){cout<<0;goto end;}
    for(i=1;i<=n;i++)d[i]=l;
    d[s]=0;

    for(j=1;j<n;j++)
        for(i=1;i<=m;i++)
            if( d[a[i][2]] > a[i][3] && d[a[i][0]] <= a[i][1] )
                d[a[i][2]] = a[i][3];

    if(d[f]==l)cout<<"-1";else
    cout<<d[f];

    end:
    return 0;
}
