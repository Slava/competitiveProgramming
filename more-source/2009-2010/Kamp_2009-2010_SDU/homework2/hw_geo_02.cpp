#include <iostream>

using namespace std;

int main()
{
    double a1,b1,a2,b2,x1,x2,y1,y2,x3,x4,y3,y4,y,x;
    cin>>x3>>y3>>x4>>y4>>x1>>y1>>x2>>y2;

    if(!(x2-x1)){
        cout<<
        ((x1<=min(x3,x4)&&x1>=max(x3,x4))
      &&((y1>=min(y3,y4)&&y1<=max(y3,y4))||(y2>=min(y3,y4)&&y2<=max(y3,y4)))
      );exit(0);}
    if(!(x4-x3)){
        cout<<
        ((x3<=min(x1,x2)&&x3>=max(x1,x2))
      &&((y3>=min(y1,y2)&&y3<=max(y1,y2))||(y4>=min(y1,y2)&&y4<=max(y1,y2)))
      );exit(0);}
    a2=(y2-y1)/(x2-x1);
    b2=y2-x2*a2;
    a1=(y4-y3)/(x4-x3);
    b1=y4-x4*a1;
    x=(b2-b1)/(a1-a2);
    y=x*a1+b1;
    cout<<(x>=min(x1,x2)&&x<=max(x1,x2)&&y>=min(y1,y2)&&y<=max(y1,y2)
    &&     x>=min(x3,x4)&&x<=max(x3,x4)&&y>=min(y3,y4)&&y<=max(y3,y4));

}
