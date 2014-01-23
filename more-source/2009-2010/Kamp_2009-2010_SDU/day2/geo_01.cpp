#include <iostream>
#include <cmath>

using namespace std;

const double p=3.14159;

int main()
{
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    printf("%f",max(atan(y1/x1)*180/p,atan(y2/x2)*180/p));

    return 0;
}
