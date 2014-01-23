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

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    Long x[2];
    int n, i;
    cin>>n;
    x[1].l(1);x[0].l(1);

    for(i=1;i<=n;i++)
        x[i%2]+=x[(i+1)%2];

    x[n%2].print();

    return 0;
}
