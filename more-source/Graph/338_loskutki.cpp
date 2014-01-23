#include <iostream>
using namespace std;

long n,m,i,j,sum=0,t;
short h[4][2]={1,0,0,1,-1,0,0,-1};
bool a[300][300];

void bfs(int y,int x)
{
    a[y][x]=0;
    for(int k=0;k<4;k++)
        if(a[y+h[k][1]][x+h[k][0]] && y+h[k][1]<n&&y+h[k][1]>=0 && x+h[k][0]<m&&x+h[k][0]>=0)
        bfs(y+h[k][1],x+h[k][0]);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
           cin>>t;a[i][j]=(!t);
        }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(a[i][j])
            {
                sum++;bfs(i,j);
            }
        }
    cout<<sum;

}
