#include <fstream.h>
#include <math.h>
#include <iostream.h>
int main () {
    ifstream fin ("1.in");
    ofstream fout ("1.out");
    int a,b,c;
    double x,y,z;
    fin>>a>>b>>c;

    y=(b*b)-4*a*c;
    x=(-b+sqrt(y))/2;
    z=(-b-sqrt(y))/2;
if ((sqrt(y)==2)||(sqrt(y)==3)||(sqrt(y)==4)||(sqrt(y)==5)||(sqrt(y)==6)||(sqrt(y)==7)||(sqrt(y)==8)||(sqrt(y)==9)||(sqrt(y)==10)||(sqrt(y)==11)||(sqrt(y)==12)||(sqrt(y)==13))
  {  fout<<"x1="<<x<<endl;
    fout<<"x2="<<z<<endl;
    fout<<"a*x*x+b*x+c="<<a*x*x+b*x+c<<endl;}
else

{    fout<<"No real roots"<<endl;
}

fin.close();
fout.close();


return 0;
}
