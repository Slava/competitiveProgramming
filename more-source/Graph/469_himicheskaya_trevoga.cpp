#include <fstream>
using namespace std;

int n,m,k,i,j,a[50][50],b[50][50],l=1,dx,dy,
    qx[10000],qy[10000],h[4][2]={0,1,1,0,0,-1,-1,0};

int main ()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            {cin>>a[i][j];b[i][j]=999999999;}
    qx[0]=qy[0]=0;b[0][0]=a[0][0];
    for(i=0;i<l;i++)
        for(j=0;j<4;j++)
        {
            dx=qx[i]+h[j][0];
            dy=qy[i]+h[j][1];
            if(dx>=0&&dx<m&&dy>=0&&dy<n
            && b[dy][dx] > b[qy[i]][qx[i]] + a[dy][dx])
            {
                b[dy][dx] = b[qy[i]][qx[i]] + a[dy][dx];
                qx[l]=dx;qy[l]=dy;l++;
            }
        }
    cout<<b[n-1][m-1];


    return 0;
}
