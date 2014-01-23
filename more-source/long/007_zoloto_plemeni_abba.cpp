#include <iostream>
using namespace std;
const int m=2000;
void r(short a[m],long &size);
void p(short a[m],long size);
int cmp(short a[m],long as,short b[m],long bs)
{
    if(as>bs)return -1;
    if(as<bs)return 1;
    for(int i=0;i<as;i++)
        if(a[i]>b[i])return -1;
        else if(a[i]<b[i])return 1;

    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    short a[m],b[m],c[m],ac,ab,bc;
    long as,bs,cs;
    r(a,as);r(b,bs);r(c,cs);
    ac=cmp(a,as,c,cs);
    ab=cmp(a,as,b,bs);
    bc=cmp(b,bs,c,cs);
    if((ac==-1&&ab==-1)||(ac==-1&&!ab))p(a,as);
    else if(bc==-1&&ab==1)p(b,bs);
    else p(c,cs);
}
void r(short a[m],long &size)
{
    char c[m];
    bool t=0;int j=0,len;
    cin>>c;size=strlen(c);
    for(int i=0;i<size;i++)
        a[i]=c[i]-48;
}
void p(short a[m],long size)
{
    for(int i=0;i<size;i++)cout<<a[i];
}
