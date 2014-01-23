#include <iostream>
using namespace std;

long long n,k,i,j,o,b[500][500],a[500][500]={0},m=0,f=0,s=1;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>b[i][j];
    a[1][1]=b[1][1];
    for(o=2;o<=k;o++,swap(f,s))
        for(i=1;i<=n&&i<=o;i++)
            for(j=1+(s+i+1)%2;j<=n&&j<=o;j+=2)
                a[i][j]=
                (b[i][j]+max(max(a[i][j-1],a[i][j+1]),
                max(a[i-1][j],a[i+1][j])))*(i+j<=o+1);

    for(i=1;i<=n;i++)
    for(j=1+(k+i)%2;j<=n;j+=2)
    m=max(m,a[i][j]);

    cout<<m;

}
