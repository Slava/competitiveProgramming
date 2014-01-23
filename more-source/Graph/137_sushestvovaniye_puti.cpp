#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double a[110][110],b[110][110],c=999999999;
    int n,i,j,k;

    cin>>n;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {cin>>a[i][j];
            if(!a[i][j]&&i!=j)a[i][j]=c;}

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(a[j][k]>a[j][i]+a[i][k]&&a[j][i]!=c&&a[i][k]!=c)
                   a[j][k]=a[j][i]+a[i][k];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            b[i][j]=a[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(a[j][k]>a[j][i]+a[i][k]&&a[j][i]!=c&&a[i][k]!=c)
                   a[j][k]=a[j][i]+a[i][k];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==c)cout<<"0 ";
            else if(b[i][j]>a[i][j])cout<<"2 ";
            else if(!a[i][j]&&i==j)cout<<"1 ";
            else cout<<"1 ";
        }cout<<endl;
    }
}
