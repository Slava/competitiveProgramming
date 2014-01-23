#include <iostream>
using namespace std;

int a[40][80]={0},z=0,n,k,i,nmo,npo;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>k;
    nmo=n-1;npo=n+1;
    a[1][nmo]=a[1][npo]=1;

    for(i=2;i<k;i++)
    {
        nmo--;npo++;
        a[i][nmo]=a[i][npo]=1;
        for(int j=nmo+2;j<=npo-2;j++){a[i][j]=a[i-1][j-1]+a[i-1][j+1];}
        if(i>2)a[i-1][0]=z;
        z=a[i][0];
        a[i][0]=0;
    }
    cout<<a[k-1][1];


    return 0;
}
