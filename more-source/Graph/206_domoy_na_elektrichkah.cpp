#include <iostream>
using namespace std;

long n,e,m,k,i,j,p,t,l=0;
long a[10000000][4],d[10000000];

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>e>>m;
    for(i=0;i<m;i++)
    {
        cin>>k>>p>>t;
        a[l][0]=a[l][3]=0;a[l][1]=p;a[l][2]=t;l++;
        for(j=1;j<k;j++)
        {
            int temp=p,tempt=t;
            cin>>p>>t;
            a[l][0]=temp;a[l][1]=p;a[l][2]=t;a[l][3]=tempt;l++;
        }
    }
    for(i=0;i<=n;i++)d[i]=999999999;d[1]=0;

    for(j=1;j<n;j++)
        for(i=0;i<l;i++)
            if( d[a[i][1]] > a[i][2]
            &&  d[a[i][0]] <= a[i][3] && a[i][0] )
                d[a[i][1]] = a[i][2];
    if(d[e]>10000000)cout<<"-1";
    else cout<<d[e];


    return 0;
}
