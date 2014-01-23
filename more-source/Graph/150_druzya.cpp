#include <iostream>
using namespace std;

int a[101][101],n,s,d[101]={0};
bool u[101]={0};

void dfs(int x)
{
    u[x]=1;
    for(int i=0;i<n;i++)
        if(!u[i]&&a[x][i])
            {d[i]++;dfs(i);}
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i,j;

    cin>>n>>s;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)u[j]=0;
        dfs(i);
    }
    cout<<d[s-1];

    return 0;
    }
