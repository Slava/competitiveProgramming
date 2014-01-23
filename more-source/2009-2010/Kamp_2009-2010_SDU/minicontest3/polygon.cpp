#include <iostream>
#include <cmath>
using namespace std;

struct dot
{
    double x,y;
};

bool online(dot a,dot b,dot c)
{
    return ((fabs((c.x-b.x)*(a.y-b.y)-(c.y-b.y)*(a.x-b.x)))<=0.01
    &&(a.x>=min(b.x,c.x)&&a.x<=max(b.x,c.x)&&a.y>=min(b.y,c.y)&&
    a.y<=max(b.y,c.y)));
}

double q(dot a,dot b,dot c)
{
    return fabs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2;
}
int main ()
{
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
    dot a[100000],t;
    int n,i,j,s=0,k,l,b=0;
    double R=0,z,maxx=-10000,minx=10000,maxy=-10000,miny=10000;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        maxx=max(maxx,a[i].x);
        minx=min(minx,a[i].x);
        maxy=max(maxy,a[i].y);
        miny=min(miny,a[i].y);
    }
    if(n>3){
    for(i=1;i<n-1;i++)
        R+=q(a[0],a[i],a[i+1]);
    R+=q(a[0],a[n],a[1]);}
    else R=q(a[0],a[1],a[2]);
        for(k=(int)minx-2;k<=(int)maxx+2;k++)
            for(l=(int)miny-2;l<=(int)maxy+2;l++)
            {
                z=0;
                t.x=k;t.y=l;
                for(i=0;i<n;i++)
                    if(online(t,a[i],a[(i+1)%n])){s++;continue;}
                for(i=0;i<n;i++)
                    z+=q(t,a[i],a[(i+1)%n]);

                if(fabs(R-z)<=0.0001)s++;
            }
    cout<<s;
}


