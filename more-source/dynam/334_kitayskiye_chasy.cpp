#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long  n,a[60001]={0},b[60001]={0},i,j,m=0;
    char s[20];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        bool t;
        t=(s[1]!=':');
        for(j=0;j<8;j++)s[j]-=48;
        a[i]=(t)?s[0]*36000+(s[1]-1)*3600+s[3]*600+s[4]*60+s[6]*10+s[7]
                 :(s[0]-1)*3600+s[2]*600+s[3]*60+s[5]*10+s[6];
    }
    sort(a,a+n);
    for(i=1;i<n;i++)
        b[0] += 43200-(a[i]-a[0]);
    for(i=1;i<n;i++)
        b[i] = b[i-1] - 43200 + n*(a[i]-a[i-1]);
    for(i=1;i<n;i++)
        if(b[m] > b[i])m = i;
        else if(b[m] == b[i])
            if (a[m] > a[i])m = i;

    cout<<a[m]/3600+1<<":";
    a[m]-=(a[m]/3600)*3600;
    if(a[m]/60<10)cout<<0;
    cout<<a[m]/60<<":";
    if(a[m]%60<10)cout<<0;
    cout<<a[m]%60<<endl;
}
