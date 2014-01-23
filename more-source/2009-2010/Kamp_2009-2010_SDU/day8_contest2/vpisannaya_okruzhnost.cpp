#include <iostream>
#include <cmath>
using namespace std;
#define eps 1e-7

    double a1,b1,c1,a2,b2,c2,a3,b3,c3;
void median (double x0,double y0,double x1,double y1,double x2,double y2,int y)
{
    double d1=sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)),x3,y3;
    double d2=sqrt((x2-x0)*(x2-x0)+(y2-y0)*(y2-y0));
    x1 = x1-x0;
    x2 = x2-x0;
    y1 = y1-y0;
    y2 = y2-y0;

    x3 = x1 / d1 + x2 / d2;
    y3 = y1 / d1 + y2 / d2;

    if( (fabs(x3) < eps) && (fabs(y3) < eps) )
    {
        switch(y)
        {
            case 1:a1=x1; b1=y1; c1=-x0 * x1 - y0 * y1;break;
            case 2:a2=x1; b2=y1; c2=-x0 * x1 - y0 * y1;break;
            case 3:a3=x1; b3=y1; c3=-x0 * x1 - y0 * y1;break;
        }
    }
    else
    {
        switch(y)
        {
            case 1:a1=-y3; b1=x3; c1=y3 * x0 - x3 * y0;break;
            case 2:a1=-y3; b1=x3; c1=y3 * x0 - x3 * y0;break;
            case 3:a3=-y3; b3=x3; c3=y3 * x0 - x3 * y0;break;
        }
    }

}
int main()
{

    double x0,y0,x1,y1,x2,y2;
    cin>>x0>>y0>>x1>>y1>>x2>>y2;
    median(x0,y0,x1,y1,x2,y2,1);
    median(x1,y1,x0,y0,x2,y2,2);
    median(x2,y2,x0,y0,x1,y1,3);
    cout.precision(6);
    cout<<fixed<<((b1*c2- b2*c1) /( a1*b2 - a2*b1))<<' '<<((a2*c1-a1*c2) / (a1*b2 - a2*b1));
}
