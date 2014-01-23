#include <iostream>

using namespace std;

int a[500][500],b[500][500],n,i,j;

int main()
{
    cin >> n;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            b[i][j] = max ( max(a[i][j],a[i][j-1]),max(a[i-1][j-1],a[i+1][j-1]) );
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout << b[i][j]<<' ';
        cout<<endl;
    }

}
