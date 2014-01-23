#include <iostream>
using namespace std;

class Long
{
public:
    Long()
    {
        for(int i=0;i<300;i++)
            a[i]=0;s=0;
    }
    void l(long z)
    {
        s=0;
        while(z)
        {
            a[s]=z%1000;
            z/=1000;s++;
        }
    }
    void operator +=(Long right)
    {
        short carry=0;
        s=max(s,right.s);
        for(int i=0;i<s;i++)
        {
            a[i] += right.a[i] + carry;
            carry = a[i] / 1000;
            a[i] %= 1000;
        }
        if(carry)
        {
            a[s]=carry;
            s++;
        }
    }
    void print ()
    {
        cout<<a[s-1];
        for(int i=s-2;i>=0;i--)
        {
            if(a[i]<100)cout<<0;
            if(a[i]<10)cout<<0;
            cout<<a[i];
        }
    }
    short a[300],s;


};

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long n,i;
    Long a[102];
    char s[200];
    cin>>s;
    a[0].l(1);
    a[1].l(1);
    for(i=1;i<strlen(s);i++)
    {
        if((s[i-1]>='1'&&s[i-1]<='2') || (s[i-1]=='3'&&s[i]>='0'&&s[i]<='3'))
            a[i+1]+=a[i-1];
        a[i+1]+=a[i];
    }
    a[strlen(s)].print();
}
