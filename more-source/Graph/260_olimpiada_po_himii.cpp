#include <iostream>
#include <algorithm>
using namespace std;

int i,j,n,m,k,s,c=100000000,d[10001],x[10001], u[10001]={0},a[1001][1001];
pair<int,int>b[10001];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m>>k>>s;
    for(i=1;i<=k;i++)cin>>x[i];
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=c;
    for(i=0;i<m;i++)
    {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        a[t1][t2]=a[t2][t1]=t3;
    }
    for(i=0;i<=n;i++)d[i]=c;
    d[0]++;d[s]=0;

    for(i=1;i<=n;i++)
    {
        m=0;
        for(j=1;j<=n;j++)
            if(!u[j] && d[j] < d[m])
                m=j;
        u[m]=1;
        for(j=1;j<=n;j++)
            d[j]=min(d[j], d[m]+a[m][j]);
    }
    for(i=0;i<k;i++)
        b[i]=make_pair(d[x[i+1]],x[i+1]);
    sort(b,b+k);

    for(i=0;i<k;i++)
        cout<<b[i].second<<' '<<b[i].first<<endl;

}

