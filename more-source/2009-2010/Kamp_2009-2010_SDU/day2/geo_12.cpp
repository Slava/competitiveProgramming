#include <iostream>

using namespace std;

int main()
{
    double a1,b1,c1,a2,b2,c2,x,y;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    y=(a1*c2-a2*c1)/(a2*b1-a1*b2);
    x=(-b1*y-c1)/a1;
    cout.precision(2);
    cout<<fixed<<x<<' '<<y;

}

