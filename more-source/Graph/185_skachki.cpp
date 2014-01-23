#include<iostream>
using namespace std;

bool a[1000][1000],u[1000];
int n,win,s,f=1,d[1000];

void dfs(int x)
{
    u[x]=1;d[x]++;
    for(int i=1;i<=n;i++)
        if(!u[i]&&a[x][i])dfs(i);
}

int main () {
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

    cin>>n>>win;
    while(f)
    {
        cin>>f; if(!f) break;
        cin>>s;
        a[s][f]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)u[j]=0;
        dfs(i);
    }
    if(d[win]==n)cout<<"Yes";
    else cout<<"No";

    return 0;

    }

