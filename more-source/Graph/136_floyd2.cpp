#include <iostream>
using namespace std;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,a[100][100],i,k,j,s=-1;
    cin>>n;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(a[j][i]>=0&&a[i][k]>=0)
                    if(a[j][k]==-1)a[j][k]=a[j][i]+a[i][k];
                    else if(a[j][i]+a[i][k]<a[j][k])
                        a[j][k]=a[j][i]+a[i][k];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s=max(s,a[i][j]);
cout<<s;
    return 0;
}
