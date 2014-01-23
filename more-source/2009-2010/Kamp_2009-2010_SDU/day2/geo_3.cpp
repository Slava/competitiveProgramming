#include <iostream>

using namespace std;

int main()
{
    double a1,b1,a2,b2,x1,y1,x3,x4,y3,y4,y,x;
    cin>>x3>>y3>>x4>>y4>>x1>>y1;

    if(!(x4-x3)){
        cout<<
        (y1>=min(y3,y4)&&y1<=max(y3,y4));exit(0);}
    a1=(y4-y3)/(x4-x3);
    b1=y4-x4*a1;
    a2=-1/a1;
    b2=y1-x1*a1;
    x=(b2-b1)/(a1-a2);
    y=x*a1+b1;
    cout<<(x>=min(x3,x4)&&x<=max(x3,x4)&&y>=min(y3,y4)&&y<=max(y3,y4));

}
