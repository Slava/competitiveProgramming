#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int a[101][101],n,x,y,j,dim=1,i;
    cin>>n;
    x=y=1;
    for(i=1;i<=n*n;i++)
    {
        a[y][x]=i;
        if(dim)
        {
            if(x==1||y==n)
            {
                dim=0;
                if(y==n)x++;
                else y++;
            }
            else
            {
                y++;x--;
            }
        }
        else if(!dim)
        {
            if(y==1||x==n)
            {
                if(x==n)y++;
                else x++;
                dim=1;
            }
            else 
            {
                y--;x++;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<' ';cout<<endl;
    }
}
