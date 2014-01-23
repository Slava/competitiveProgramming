#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int b[999][999], o, c[999][999], m, n, l;
string a[999];
main ()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>n>>m;
    o=m+n;
    for (int i=0 ; i<n ; i++)
        cin>>a[i];

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            b[n-i-1][j]=(int)a[i][j]-48;

        }

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (i==0 && j==0)c[i][j]=b[i][j];
            else if (i==0)c[i][j]=b[i][j]*c[i][j-1];
            else if (j==0) c[i][j]=b[i][j]*c[i-1][j];
            else if (b[i][j]==1)c[i][j]=c[i][j-1]+c[i-1][j];


        }
    if (c[n-1][m-1]==0)
    {
        cout<<"impossible";
    }
    else
        cout<<c[n-1][m-1];

}
