#include <iostream>

using namespace std;

int main()
{
    double xa,ya,xb,yb,xc,yc;
    //(y-y1)/(y2-y1)=(x-x1)/(x2-x1)
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    cout<<(((ya-yb)/(yc-yb)==(xa-xb)/(xc-xb))
    &&(xa>=min(xb,xc)&&xa<=max(xb,xc)&&ya>=min(yb,yc)&&ya<=max(yb,yc)));

    return 0;
}
