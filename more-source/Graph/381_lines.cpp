#include <iostream>
using namespace std;

int h[4][2]={1,0,0,1,-1,0,0,-1},qx[10000],qy[10000],l=1;
int a[60][60],n,i,j,fy,fx,sx,sy;

main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char t[1000];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t;
        for(j=0;j<n;j++)
        {
           if(t[j]=='O')a[i][j]=-999999;else
           if(t[j]=='.')a[i][j]=999999;else
           if(t[j]=='@'){a[i][j]=0;qx[0]=j;qy[0]=i;}else
           if(t[j]=='X'){fy=i;fx=j;a[i][j]=999999;}
        }
    }
    for(i=0;i<l;i++)
        for(j=0;j<4;j++)
        {
            if(qx[i]+h[j][0]<n && qx[i]+h[j][0]>=0 &&
               qy[i]+h[j][1]<n && qy[i]+h[j][1]>=0 &&
               a[qy[i]+h[j][1]][qx[i]+h[j][0]] > a[qy[i]][qx[i]]+1)
            {
                a[qy[i]+h[j][1]][qx[i]+h[j][0]] = a[qy[i]][qx[i]]+1;
                qy[l]=qy[i]+h[j][1];qx[l]=qx[i]+h[j][0];l++;
            }
        }
    if(a[fy][fx]>2500){cout<<"No";goto end;}
    else cout<<"Yes"<<endl;
    while(true)
    {
        for(j=0;j<4;j++)
            if(a[fy+h[j][1]][fx+h[j][0]]==a[fy][fx]-1)
                {sx=fx+h[j][0];sy=fy+h[j][1];break;}
        a[fy][fx]=-1;fx=sx;fy=sy;
        if(!a[sy][sx])break;
    }


     for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            if(!a[i][j])cout<<'@';else
            if(a[i][j]==-999999)cout<<'O';else
            if(a[i][j]==-1)cout<<'+';
            else cout<<'.';
            //cout<<a[i][j]<<' ';
        }cout<<endl;
    }
end:
;
}
