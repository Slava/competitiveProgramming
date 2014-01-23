#include <iostream>

using namespace std;

int main ()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

    char s[105];
    short a[105]={0},b[105]={0},i,c=0,z,x;
    cin>>s;z=strlen(s);
    for(i=0;i<z;i++)
        a[i]=s[z-i-1]-48;
    cin>>s;x=strlen(s);
    for(i=0;i<x;i++)
        b[i]=s[x-i-1]-48;
    x=max(x,z);
    for(i=0;i<x;i++)
    {
        a[i]+=b[i]+c;
        c=a[i]/10;
        a[i]-=c*10;
    }
    if(c){a[x]=c;x++;}
    for(i=x-1;i>=0;i--)
        cout<<a[i];

}
