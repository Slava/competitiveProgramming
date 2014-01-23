#include <iostream>
using namespace std;

long a[10001][3],n,m,d[2005],i,j,c=1000000,l,k;
bool FLAG=0,u[2005]={0},q[10001]={0},u2[2005]={0},q2[10005]={0};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(i=0;i<m;i++)
        {cin>>a[i][0]>>a[i][1]>>a[i][2];a[i][2]*=-1;}

    for(i=1;i<=n;i++)d[i]=c;d[1]=0;
u[1]=2;
    for(k=1;k<n;k++)
        for(j=0;j<m;j++){
            if(d[a[j][1]]>d[a[j][0]]+a[j][2]&&d[a[j][0]]!=c)
               d[a[j][1]]=d[a[j][0]]+a[j][2];
            if(u[a[j][0]]){q[j]=u[a[j][1]]=1;}
        }


    if(d[n]>c/2){cout<<":(";goto end;}

    u2[n]=1;
    for(k=1;k<=n;k++)
        for(j=0;j<m;j++){
            if(d[a[j][1]]>d[a[j][0]]+a[j][2]&&d[a[j][0]]!=c)
            {
                d[a[j][1]]=d[a[j][0]]+a[j][2];
                if(q[j]&&q2[j])FLAG=1;
            }
            if(u2[a[j][1]]){q2[j]=1;u2[a[j][0]]=1;}
        }

    if(FLAG)cout<<":)";
    else cout<<d[n]*-1;
    end:;
}

