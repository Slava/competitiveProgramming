#include <iostream>
using namespace std;

long long n,i,j,m=2,two=1,z,t,prem=1;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;if(n==1){cout<<1;exit(0);}
    for(i=3;i<=n;i++)
    {
        t=two*2+1;
        while(t)
        {
            prem=m;
            if(t%10+m%10>9)m++;
            m+=t;
            t/=10;
        }
        if(m%10==0)m++;

        if(i%2==0)two++;
    }
    cout<<m;
}
