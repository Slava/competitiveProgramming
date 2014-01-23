#include <iostream>
using namespace std;

int n,m,a[101][101]={0},i,j,t;
bool u[101];

int dfs(int x,int k)
{
    u[x]=1;
    for(int i=0;i<n;i++)
        if(a[x][i])
            if(!u[i])dfs(i,k);
            else if(i==k){cout<<"No";exit(0);}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>t>>j;a[t-1][j-1]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)u[j]=0;
        dfs(i,i);
    }
    cout<<"Yes";
}
