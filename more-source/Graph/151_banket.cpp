#include <iostream>
using namespace std;

int n,m,a[105][105],de[105],u[105],l=1;

void dfs(int x,int d)
{
    u[x]=1;
    de[x]=d;
    for(int i=1;i<=n;i++)
        if(a[x][i]){
            if(!u[i])dfs(i,d+1);
            else{
                if((de[i]-de[x])%2==0&&abs(de[i]-de[x])>1)
                    {cout<<"NO";exit(0);}
            }
        }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1][t2]=a[t2][t1]=1;
    }
    for(int i=1;i<=n;i++)
        if(!u[i])dfs(i,1);
    cout<<"YES";
}
