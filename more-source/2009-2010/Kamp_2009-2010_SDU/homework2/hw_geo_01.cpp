#include <iostream>

using namespace std;

int main()
{
    double a1,b1,a2,b2,x1,x2,y1,y2,y,x;
    cin>>a1>>b1>>x1>>y1>>x2>>y2;

    a2=(y2-y1)/(x2-x1);
    b2=y2-x2*a2;
    x=(b2-b1)/(a1-a2);
    y=x*a1+b1;
    cout<<(x>=min(x1,x2)&&x<=max(x1,x2)&&y>=min(y1,y2)&&y<=max(y1,y2));

}
