#include<iostream>
using namespace std;

int main () {
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

    int a[100][100],n,i,j,k,sum=100000000;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            for(k=j+1;k<n;k++)
                sum=min(sum,a[i][j]+a[j][k]+a[k][i]);

    cout<<sum;

    return 0;
    }

