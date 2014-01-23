#include <iostream>
using namespace std;
const int m=50001;
void r(short a[m],short &z);
void mi(short a[m],short as,short b[m]);
int cmp(short a[m],short as,short b[m],short bs)
{
    if(as>bs)return -1;
    if(as<bs)return 1;
    for(int i=as-1;i>=0;i--)
        if(a[i]>b[i])return -1;
        else if(a[i]<b[i])return 1;

    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    short a[m],b[m],sa,sb,cm;
    r(a,sa);r(b,sb);
    cm=cmp(a,sa,b,sb);
    if(!cm)cout<<"0";
    else if(cm==-1)mi(a,sa,b);
    else if(cm==1){cout<<"-";mi(b,sb,a);}

}
void r(short a[m],short &z)
{
    char s[m];
    cin>>s;z=strlen(s);
    for(int i=0;i<z;i++)
        a[i]=s[z-i-1]-48;
}
void mi(short a[m],short as,short b[m])
{
    short c=0,f=0;
    for(int i=0;i<as;i++)
    {
        a[i]-=c+b[i];
        if(a[i]<0){c=1;a[i]+=10;}
        else c=0;
    }
    for(int i=as-1;i>=0;i--)
    {
        if(!a[i]&&!f)continue;
        f=1;cout<<a[i];
    }
}
