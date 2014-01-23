#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m,a[500][500],i,j,k,l,p,maxi=0;
    cin>>n>>m;if(!n&&!m){cout<<0;exit(0);}
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            if(!i&&j)a[i][j]=a[i][j]+a[i][j-1];
            else if(i&&!j)a[i][j]=a[i][j]+a[i-1][j];
            else if(i&&j)a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(k=i;k<n;k++)
                for(l=j;l<m;l++)
                {
                    p=a[k][l];
                    if(j>0)p-=a[k][j-1];
                    if(i>0)p-=a[i-1][l];
                    if(i>0&&j>0)p+=a[i-1][j-1];
                    maxi=max(maxi,p);
                }

   cout<<maxi;

    return 0;
}
