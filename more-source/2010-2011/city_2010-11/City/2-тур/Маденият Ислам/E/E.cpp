#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long int n,m,a[1010][1010],i,j,h[2][2]={-1,0,0,1},x[999999],y[999999],k=1,c[1010][1010];
char s;
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin>>s;
            a[i][j]=s-48;
        }
    if(!a[n-1][0])cout<<"impossible";
    else if(n==1 && m==1)cout<<1;
    else
    {
        x[0]=n-1,y[0]=0;
        c[x[0]][y[0]]=1;
        for(i=0;i<k;i++)
            for(j=0;j<2;j++)
            {
                if(x[i]+h[j][0]>=0 && y[i]+h[j][1]<m && a[x[i]+h[j][0]][y[i]+h[j][1]]>0)
                {
                    a[x[i]+h[j][0]][y[i]+h[j][1]]++;
                    c[x[i]+h[j][0]][y[i]+h[j][1]]=c[x[i]][y[i]]+1;
                    x[k]=x[i]+h[j][0],
                    y[k]=y[i]+h[j][1];
                    if(c[x[k]][y[k]]>n+m-1)cout<<"impossible",exit(0);
                    k++;
                }

            }

        if(a[0][m-1]<2)
            cout<<"impossible";
        else
            cout<<a[0][m-1]-1;
    }
    return 0;
}
