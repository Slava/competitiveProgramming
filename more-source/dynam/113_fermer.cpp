#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    short n,i,j,a[2][1005],m=1;
    char t[1001];
    bool t1=1,t2=0;
    cin>>n;
    cin>>t;
    for(j=0;j<n;j++)
        a[0][j]=t[j]-48;
    for(i=1;i<n;i++)
    {
        cin>>t;
        for(j=0;j<n;j++)
            a[t1][j]=t[j]-48;
        for(j=1;j<n;j++)
        {
            if(a[t1][j]&&a[t2][j]&&a[t2][j-1]&&a[t1][j-1])
                a[t1][j]+=min(min(a[t2][j],a[t2][j-1]),a[t1][j-1]);
            m=max(m,a[t1][j]);
        }
        swap(t1,t2);
    }
    cout<<m*m;

}
