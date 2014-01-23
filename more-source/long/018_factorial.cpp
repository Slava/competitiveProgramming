#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    short a[10005]={1};
    long size=1,n,i,j,c=0;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<size;j++)
        {
            a[j]=a[j]*i+c;
            c=a[j]/10;
            a[j]=a[j]%10;
        }
        while(c>0)
        {
            a[size]=c%10;
            c/=10;size++;
        }
    }
    for(i=size-1;i>=0;i--)
        cout<<a[i];

}
