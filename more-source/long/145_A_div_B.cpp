#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    short a[2000];long b,size,i,f=0,c=0,o;
    char s[2000];
    cin>>s>>b;
    size=strlen(s);
    for(i=0;i<size;i++)
        a[i]=s[i]-48;
    for(i=0;i<size;i++)
    {
        o=(c*10+a[i])/b;
        c=(c*10+a[i])%b;
        if(!o)if(f||i==size-1)cout<<0;else ;
        else {f=1;cout<<o;}
    }

    return 0;
}
