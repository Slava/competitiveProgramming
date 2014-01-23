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
        a[0]=2;
        s=1;
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
    void operator -=(Long right)
    {
        short carry=0;
        s=max(s,right.s);
        for(int i=0;i<s;i++)
        {
            a[i] -= right.a[i] + carry;
            if(a[i] < 0)
            {
                carry = 1;
                a[i] += 1000;
            }
            else carry = 0;
        }
        while(!a[s-1])s--;
    }
    void operator =(Long right)
    {
        s = right.s;
        for(int i=0;i<s;i++)
            a[i] = right.a[i];
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
    void scan()
    {
        char str[1000];
        short t;
        s = 0;
        cin>>str;
        if(strlen(str)==1&&str[0]=='1'){cout<<1;exit(0);}
        for(int i=strlen(str)-1;i>=0;i--)
        {
            if((strlen(str)-1-i)%3==0)t=str[i]-48;
            if((strlen(str)-1-i)%3==1){t+=(str[i]-48)*10;}
            if((strlen(str)-1-i)%3==2){a[s] = t + (str[i]-48)*100;s++;t = 0;}
        }
        if(t){a[s] = t;s++;}
    }
    short a[300],s;


};

int main()
{
    Long A,B,C;
    A.scan();
    B=A;
    C.l(2);
    B-=C;
    A+=B;
    A.print();
}
