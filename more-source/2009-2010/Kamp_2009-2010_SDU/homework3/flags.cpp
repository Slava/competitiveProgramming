#include <fstream>
#include <iostream>
using namespace std;

ifstream cin("flags.in");
ofstream cout("flags.out");

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
        ifstream cin("flags.in");
    ofstream cout("flags.out");

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
int main()
{
    ifstream cin("flags.in");
    ofstream cout("flags.out");

    Long w[100],b[100],r[100];
    int n,i;
    w[0].l(1);
    r[0].l(1);
    cin>>n;

    for(i=1;i<n;i++)
    {
        w[i]+=r[i-1];
        b[i]+=r[i-1];w[i+1]+=r[i-1];
        b[i]+=w[i-1];r[i+1]+=w[i-1];
        r[i]+=w[i-1];
    }
    w[n-1]+=r[n-1];
    w[n-1].print();
}
