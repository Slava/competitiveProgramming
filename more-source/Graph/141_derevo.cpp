#include <iostream>
using namespace std;

bool a[101][101];
int n,u[101]={0};

void dfs(int x, int xx)
{
    u[x]=1;
    for(int i=0;i<n;i++)
        if(a[x][i])
            if(!u[i])dfs(i,x);
            else{if(i==xx)continue;cout<<"NO";exit(0);}
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i,j,sum=0;

    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    dfs(0,0);
    for(i=0;i<n;i++)sum+=u[i];
    if(sum==n)cout<<"YES";
    else cout<<"NO";

    return 0;
    }
