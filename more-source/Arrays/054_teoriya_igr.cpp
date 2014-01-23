#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int a[200][200],n,m,maxi[200]
    ,minj[200],i,j,z=-2000,x=2000;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            {cin>>a[i][j];
            minj[i]=2000;
            maxi[j]=-2000;}

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            minj[i]=min(minj[i],a[i][j]);

    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
            maxi[j]=max(maxi[j],a[i][j]);

    for(i=0;i<n;i++)
        z=max(z,minj[i]);
    cout<<z<<' ';
    for(j=0;j<m;j++)
        x=min(x,maxi[j]);
    cout<<x;
}
