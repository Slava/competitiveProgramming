#include <iostream>
using namespace std;

int main (){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,i,j,k,a[260][260]={0};
    cin>>n;
    for(i=0;i<=n;i++)for(j=0;j<=n;j++)a[i][j]=999999;
    for(i=0;i<=n;i++)
        for(j=i+1;j<=n;j++)
            cin>>a[i][j];

    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            for(k=0;k<=n;k++)
                if(i>j&&k>i&&a[j][i]+a[i][k]<a[j][k])
                a[j][k]=a[j][i]+a[i][k];
    cout<<a[0][n];


    return 0;
    }
