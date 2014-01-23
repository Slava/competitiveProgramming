#include <iostream>

using namespace std;

int n,m,a[100][500];

bool u[100][500];

void clear()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            a[i][j]=0;
}

int p(int ii,int jj)
{
    int sum=0;
    int check=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            check+=u[i][j];

    if(!ii&&!jj&&check==n*m)return 1;
    if(ii+1<n&&!u[ii+1][jj])
    {
        u[ii+1][jj]=1;
        sum+=p(ii+1,jj);
        u[ii+1][jj]=0;
    }
    if(jj+1<m&&!u[ii][jj+1])
    {
        u[ii][jj+1]=1;
        sum+=p(ii,jj+1);
        u[ii][jj+1]=0;
    }
    if(ii-1>=0&&!u[ii-1][jj])
    {
        u[ii-1][jj]=1;
        sum+=p(ii-1,jj);
        u[ii-1][jj]=0;
    }
    if(jj-1>=0&&!u[ii][jj-1])
    {
        u[ii][jj-1]=1;
        sum+=p(ii,jj-1);
        u[ii][jj-1]=0;
    }

    return sum;
}


int main()
{
    cin>>n>>m;
    if(n%2&&m%2){cout<<0;exit(0);}
    else if(n==3){cout<<(1<<(m/2));}
    else cout<<p(0,0);

}
