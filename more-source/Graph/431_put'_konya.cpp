#include <fstream>
using namespace std;

int a[60][60],n,fx,fy,l=0,qx[10000],qy[10000],i,j,sx,sy;
int h[8][2]={-1,-2,1,-2,-2,-1,-2,1,-1,2,1,2,2,-1,2,1};

main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin>>n;
    char s;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {cin>>s;
            if(s=='.')a[i][j]=999999;else
            if(s=='#')a[i][j]=-999999;else
            if(s=='@'){
                if(!l){a[i][j]=0;l++;qx[0]=j;qy[0]=i;}
                else {a[i][j]=999999;fy=i;fx=j;}
                }
        }
    }
    for(i=0;i<l;i++)
        for(j=0;j<8;j++)
            if(qx[i]+h[j][0]<n && qx[i]+h[j][0]>=0 &&
               qy[i]+h[j][1]<n && qy[i]+h[j][1]>=0 &&
               a[qy[i]+h[j][1]][qx[i]+h[j][0]] > a[qy[i]][qx[i]]+1)
            {
                a[qy[i]+h[j][1]][qx[i]+h[j][0]]=a[qy[i]][qx[i]]+1;
                qy[l]=qy[i]+h[j][1];
                qx[l]=qx[i]+h[j][0];
                l++;
            }
    if(a[fy][fx]==999999){cout<<"Impossible";goto end;}
    while(true)
    {
        for(j=0;j<8;j++)
            if(a[fy+h[j][1]][fx+h[j][0]]==a[fy][fx]-1)
                {sx=fx+h[j][0];sy=fy+h[j][1];break;}
        a[fy][fx]=0;fx=sx;fy=sy;
        if(!a[sy][sx])break;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]<0)cout<<'#';else
            if(a[i][j]>0)cout<<'.';else
            if(!a[i][j])cout<<'@';
        }
        cout<<endl;
    }

    end:;
}
