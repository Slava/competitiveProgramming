#include <iostream>
using namespace std;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    bool a[200][200];
    int n,s,f,i,j,k,d[200];
    cin>>n;

    for(i=0;i<n;i++)d[i]=30000;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    cin>>s>>f;
    d[s-1]=0;
    for(k=1;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j])d[j]=min(d[j],d[i]+1);
    if(d[f-1]>15000)cout<<"-1";else
    cout<<d[f-1];

    return 0;
}
