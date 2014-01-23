#include <fstream>
using namespace std;

ifstream cin("hourse.in");
ofstream cout("hourse.out");

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
    Long a[100][10],sum;
    int n,i=2;
    cin>>n;
    a[1][1].l(1);
    a[1][2].l(1);
    a[1][3].l(1);
    a[1][4].l(1);
    a[1][5].l(1);
    a[1][6].l(1);
    a[1][7].l(1);
    a[1][9].l(1);
    for(;i<=n;i++)
    {
        a[i][0]+=a[i-1][4];
        a[i][0]+=a[i-1][6];
        a[i][1]+=a[i-1][8];
        a[i][1]+=a[i-1][6];
        a[i][2]+=a[i-1][7];
        a[i][2]+=a[i-1][9];
        a[i][3]+=a[i-1][4];
        a[i][3]+=a[i-1][8];
        a[i][4]+=a[i-1][3];
        a[i][4]+=a[i-1][9];
        a[i][4]+=a[i-1][0];
        a[i][6]+=a[i-1][0];
        a[i][6]+=a[i-1][7];
        a[i][6]+=a[i-1][1];
        a[i][7]+=a[i-1][6];
        a[i][7]+=a[i-1][2];
        a[i][8]+=a[i-1][1];
        a[i][8]+=a[i-1][3];
        a[i][9]+=a[i-1][4];
        a[i][9]+=a[i-1][2];
    }
    for(i=0;i<10;i++)
        sum+=a[n][i];
    sum.print();

}

