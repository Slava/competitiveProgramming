#include <iostream>
using namespace std;

int a[25][25]={0},n,x1,y1,x2,y2,l=1,qx[10000],qy[10000],i,j;
int hod[8][2]={-1,-2,1,-2,-2,-1,-2,1,-1,2,1,2,2,-1,2,1};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=9999;
    cin>>x1>>y1>>x2>>y2;
    a[y1][x1]=0;
    qx[0]=x1;
    qy[0]=y1;
    for(i=0;i<l;i++)
        for(j=0;j<8;j++)
            if(qx[i]+hod[j][0]<=n && qx[i]+hod[j][0]>0 && qy[i]+hod[j][1]<=n && qy[i]+hod[j][1]>0 && a[qy[i]+hod[j][1]][qx[i]+hod[j][0]] > a[qy[i]][qx[i]]+1)
            {
                a[qy[i]+hod[j][1]][qx[i]+hod[j][0]]=a[qy[i]][qx[i]]+1;
                qy[l]=qy[i]+hod[j][1];
                qx[l]=qx[i]+hod[j][0];
                l++;
            }
    cout<<a[y2][x2];
}
