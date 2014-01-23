#include <iostream>
using namespace std;

int main ()
{
   freopen("plates.in","r",stdin);
   freopen("plates.out","w",stdout);
    long int a[5002],b[5002],n,i,j,maxi;
    cin>>n;
    b[0]=1;
    cin>>a[0];
    for(i=1;i<n;++i)
    {
        cin>>a[i];
        maxi=0;
        for(j=i-1;j>=0;--j)
        {
            if(a[j]>a[i]&&b[j]>maxi){maxi=b[j];}
        }
        b[i]=maxi+1;
    }
    cout<<b[n-1];

    return 0;
}
