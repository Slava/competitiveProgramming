#include <iostream>
using namespace std;

bool  u[30003];
int n,A,B,i,a[30003],x;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>A>>B;
    for(i=2;i<=n;i++)
        {cin>>a[i];u[i]=0;}
    a[0]=a[1]=u[1]=0;
    x=A;
    while(x)
    {
        u[x]=1;
        x=a[x];
    }
    x=B;
    while(x)
    {
        if(u[x]){cout<<x;break;}
        u[x]=1;
        x=a[x];
    }

    return 0;
}
