#include <iostream>
using namespace std;

int a[9][9]={0},b[9][9]={0},x1,y1,l=1,qx[10000],qy[10000],i,j;
int hod[8][2]={-1,-2,1,-2,-2,-1,-2,1,-1,2,1,2,2,-1,2,1};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
            b[i][j]=a[i][j]=9999;
    char s[10];
    cin>>s;
    y1=s[1]-48;x1=s[0]-96;
    a[y1][x1]=0;
    qx[0]=x1;
    qy[0]=y1;
    for(i=0;i<l;i++)
        for(j=0;j<8;j++)
            if(qx[i]+hod[j][0]<9 && qx[i]+hod[j][0]>0 && qy[i]+hod[j][1]<9 && qy[i]+hod[j][1]>0 && a[qy[i]+hod[j][1]][qx[i]+hod[j][0]] > a[qy[i]][qx[i]]+1)
            {
                a[qy[i]+hod[j][1]][qx[i]+hod[j][0]]=a[qy[i]][qx[i]]+1;
                qy[l]=qy[i]+hod[j][1];
                qx[l]=qx[i]+hod[j][0];
                l++;
            }
    cin>>s;
    y1=s[1]-48;x1=s[0]-96;
    b[y1][x1]=0;
    qx[0]=x1;
    qy[0]=y1;l=1;
    for(i=0;i<l;i++)
        for(j=0;j<8;j++)
            if(qx[i]+hod[j][0]<9 && qx[i]+hod[j][0]>0 && qy[i]+hod[j][1]<9 && qy[i]+hod[j][1]>0 && b[qy[i]+hod[j][1]][qx[i]+hod[j][0]] > b[qy[i]][qx[i]]+1)
            {
                b[qy[i]+hod[j][1]][qx[i]+hod[j][0]]=b[qy[i]][qx[i]]+1;
                if(a[qy[i]+hod[j][1]][qx[i]+hod[j][0]]==b[qy[i]][qx[i]]+1){cout<<b[qy[i]][qx[i]]+1;exit(0);}
                qy[l]=qy[i]+hod[j][1];
                qx[l]=qx[i]+hod[j][0];
                l++;
            }
    cout<<-1;
}
