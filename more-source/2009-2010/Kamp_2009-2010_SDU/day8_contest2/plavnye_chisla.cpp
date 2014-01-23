#include <iostream>

using namespace std;

long long a[100][11],n,sum=0;

int main()
{
    cin>>n;
    if(n==1){cout<<9;exit(0);}
    if(n==0){cout<<0;exit(0);}
    a[2][1]=a[2][9]=2;
    a[2][0]=1;
    a[2][2]=3;
    a[2][3]=3;
    a[2][4]=3;
    a[2][5]=3;
    a[2][6]=3;
    a[2][7]=3;
    a[2][8]=3;
    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<10;j++)
            a[i][j]+=a[i-1][j-1]+a[i-1][j+1]+a[i-1][j];
    }
    for(int i=0;i<10;i++)sum+=a[n][i];
    cout<<sum;
}
