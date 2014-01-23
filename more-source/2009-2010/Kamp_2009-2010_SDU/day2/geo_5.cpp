#include <iostream>
#include <cmath>
using namespace std;

double q(double x1,double y1,double x2,double y2,double x3,double y3)
{
    return fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}

double online(double xa,double ya,double xb,double yb,double xc,double yc)
{
    return (((ya-yb)/(yc-yb)==(xa-xb)/(xc-xb))
    &&(xa>=min(xb,xc)&&xa<=max(xb,xc)&&ya>=min(yb,yc)&&ya<=max(yb,yc)));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double xa,ya,xb,yb,xc,yc,xz,yz;
    cin>>xa>>ya>>xb>>yb>>xc>>yc>>xz>>yz;

    if(q(xa,ya,xb,yb,xc,yc)==(q(xa,ya,xb,yb,xz,xz)+q(xa,ya,xz,yz,xc,yc)+q(xz,yz,xb,yb,xc,yc)))
    {
        if(online(xz,yz,xb,yb,xc,yc))
        {cout<<"on line bc";exit(0);}
        if(online(xz,xz,xa,ya,xc,yc))
        {cout<<"on line ac";exit(0);}
        if(online(xz,yz,xb,yb,xa,ya))
        {cout<<"on line ba";exit(0);}
        cout<<"Inside";
    }
    else cout<<"Outside";


    return 0;
}
