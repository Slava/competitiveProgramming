#include <iostream>
using namespace std;

int i,j,k,o,p,n,m,a[1000][1000],u[1000][1000]={0},sum=0,
h[8]={1,0,0,1,-1,0,0,-1},qx[10001],qy[100001],l;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(u[i][j])continue;
            l=1;qx[0]=j;qy[0]=i;p=1;
            for(o=0;o<l;o++){
                for(k=0;k<7;k+=2)
                {
                    int dy=qy[o]+h[k],dx=qx[o]+h[k+1];
                    if(dy>0&&dy<=n&&dx>0&&dx<=m){
                    if(a[dy][dx] == a[qy[o]][qx[o]] && !u[dy][dx])
                        {qx[l]=dx;qy[l]=dy;u[qy[l]][qx[l]]=1;l++;}
                    if(a[dy][dx] < a[qy[o]][qx[o]]){p=0;break;}
                    }
                }

            }
            sum+=p;
        }
    cout<<sum;
}
