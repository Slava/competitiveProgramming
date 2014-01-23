#include <iostream>
#include <cstdio>
using namespace std;
    long long int n,i,j,c,k,a[10010],b[10010],sum[10010];
char s;
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    while(cin>>s)
    {
        if(s>='0' && s<='9')a[i]=s-48;
        else if(s>='A' && s<='Z')a[i]=s-55;
        i++;
    }
    b[--i]=1;
    sum[i]=a[i];
    for(--i;i>=0;i--)
    {
        b[i]=(b[i+1]*n)%k;
        sum[i]+=(a[i]*b[i]+sum[i+1])%k;
    }

    cout<<sum[0]
    ;

    return 0;
}
