#include <iostream>
using namespace std;

int h[4][2]={1,0,0,1,-1,0,0,-1},qx[100000],qy[100000],l=1,dx,dy,
    a[200][200],n,m,i,j,fy,fx,sx,sy,t[200][200][2],ts,xts[15][2];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m>>sy>>sx;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            {cin>>ts;a[i][j]=(ts)?-1:999999999;}
    cin>>ts;
    for(i=0;i<ts;i++)
    {int tempx,tempy,tempy2,tempx2;
        cin>>tempy>>tempx>>tempy2>>tempx2;
        t[tempy][tempx][0]=tempy2;t[tempy][tempx][1]=tempx2;
    }
    cin>>ts;
    for(i=0;i<ts;i++)cin>>xts[i][0]>>xts[i][1];
    qx[0]=sx;qy[0]=sy;a[sy][sx]=0;

    for(i=0;i<l;i++)
    {
        for(j=0;j<4;j++)
        {
            dx=qx[i]+h[j][1];dy=qy[i]+h[j][0];
            if(dx<=m&&dx>0&&dy<=n&&dy>0&&
               a[dy][dx] > a[qy[i]][qx[i]] + 1){
               a[dy][dx] = a[qy[i]][qx[i]] + 1;
               qx[l]=dx;qy[l]=dy;l++;
               }
            if(t[qy[i]][qx[i]][0]&&t[qy[i]][qx[i]][1]&&
               a[t[qy[i]][qx[i]][0]][t[qy[i]][qx[i]][1]] > a[qy[i]][qx[i]] + 1)
            {
                a[t[qy[i]][qx[i]][0]][t[qy[i]][qx[i]][1]] = a[qy[i]][qx[i]] + 1;
                qx[l]=t[qy[i]][qx[i]][1];qy[l]=t[qy[i]][qx[i]][0];l++;
            }
        }
    }
    int mini=999999999;
    for(i=0;i<ts;i++)mini=min(mini,a[xts[i][0]][xts[i][1]]);
    if(mini==999999999)cout<<"Impossible";
    else cout<<mini+1;

}
