#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int a[100][100],n,i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(a[j][i]+a[i][k]<a[j][k])
                    {a[j][k]=a[j][i]+a[i][k];}

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}
