#include <iostream>
#include <cstdio>

using namespace std;
int n,m,a[251],i,j,t,c[251];
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=250;j++)c[j]=0;
        for(j=0;j<m;j++)
        {
            cin>>t;
            if(!c[t])
            a[t]++,c[t]++;
        }
    }

    for(i=1;i<=250;i++)
        if(a[i]>=n){cout<<i;break;}

    return 0;
}
