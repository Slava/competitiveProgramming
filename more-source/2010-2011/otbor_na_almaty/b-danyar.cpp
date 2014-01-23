#include <iostream>
#include <cstdio>
using namespace std;
int w[11][11],i,j,a,b,lx[99],ly[99],kl,sx[99],sy[99],ks,t[11][11];
char o;
void kon(int x1,int y1)
{
    int x[9]={2,2,-2,-2,1,-1,1,-1},y[9]={1,-1,1,-1,2,2,-2,-2};
    for(i=0;i<9;i++)
    {
        if(x1+x[i]>0&&x1+x[i]<9&&y1+y[i]>0&&y1+y[i]<9)
        w[x1+x[i]][y1+y[i]]=1;
    }
}
void lad(int x1,int y1)
{
    j=0;
    for(i=1;i<x1;i++)
    {
        j++;
        lx[j]=i;
        ly[j]=y1;
    }
    for(i=x1+1;i<9;i++)
    {
        j++;
        lx[j]=i;
        ly[j]=y1;
    }
    for(i=1;i<y1;i++)
    {
        j++;
        lx[j]=x1;
        ly[j]=i;
    }
    for(i=y1+1;i<9;i++)
    {
        j++;
        lx[j]=x1;
        ly[j]=i;
    }
    kl=j;
}
bool slon1(int x1,int y1,int x2,int y2)
{
    int e,e1;
    for(e=1;e<=8;e++)
    for(e1=1;e1<=8;e1++)
    t[e][e1]=0;
    int x,y;
    x=x1;
    y=y1;
    while(x>1&&y>1)
    {
       x--;y--;
        t[x][y]=1;
    }
    x=x1;
    y=y1;
    while(x>1&&y<8)
    {
       x--;y++;
        t[x][y]=1;
    }
    x=x1;
    y=y1;
    while(x<8&&y>1)
    {
        x++;y--;
        t[x][y]=1;
    }
    x=x1;
    y=y1;
    while(x<8&&y<8)
    {
        x++;y++;
        t[x][y]=1;
    }
    if(t[x2][y2]==1)
    return true;
    else
    return false;
}
void slon(int x1,int y1)
{
    int i,j;
    j=0;
    int x,y;
    x=x1;
    y=y1;
    while(x>1&&y>1)
    {
        x--;y--;
        j++;
        sx[j]=x;
        sy[j]=y;
    }
    x=x1;
    y=y1;
    while(x>1&&y<8)
    {
        x--;y++;
        j++;
        sx[j]=x;
        sy[j]=y;
    }
    x=x1;
    y=y1;
    while(x<8&&y>1)
    {
        x++;y--;
        j++;
        sx[j]=x;
        sy[j]=y;
        t[sx[j]][sy[j]]=1;
    }
    x=x1;
    y=y1;
    while(x<8&&y<8)
    {
        x++;y++;
        j++;
        sx[j]=x;
        sy[j]=y;
    }
    ks=j;
}
void prover()
{
    int i,j;
    bool ok,ok1=false;
    for(i=1;i<=ks;i++)
    {
        for(j=1;j<=kl;j++)
        {
            ok=true;
            if(w[lx[j]][ly[j]]==0&&w[sx[j]][sy[j]]==0)
            {
            if(lx[j]==sx[i]||lx[j]==sy[i]||ly[j]==sx[i]||ly[j]==sy[i])
            ok=false;
            if(slon1(sx[i],sy[i],lx[j],ly[j]))
            ok=false;
            }
            if(ok)
            {
                ok1=true;
                o=lx[j]+96;
                cout<<o<<ly[j]<<endl;
                o=sx[i]+96;
                cout<<o<<sy[i];
                break;
            }
        }
        if(ok1)
        break;
    }
}
main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    cin>>o>>b;
    a=o-96;
    kon(a,b);
    lad(a,b);
    slon(a,b);
    prover();
}
