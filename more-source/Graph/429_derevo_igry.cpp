#include <iostream>
using namespace std;

int n,a[1001],d[1001],i;

int dfs(int x,int k)
{
    if(d[x]!=2)return d[x];
    int m=3;
    if(d[x]==2)
        for(int j=1;j<n;j++)
            if(a[j]-1==x)
            {
                int t=dfs(j,k*-1);
                if(t==k)return k;
                else if(t==k*-1&&m==3)m=k*-1;
                else if(!t)m=t;
            }
    return m;

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char t;
    cin>>n;d[0]=2;
    for(i=1;i<n;i++)
    {
        cin>>t;
        if(t=='N'){cin>>a[i];d[i]=2;}
        if(t=='L'){cin>>a[i]>>d[i];}
    }
    int ans=dfs(0,1);
    if(ans>0)cout<<'+';
    cout<<ans;
}
