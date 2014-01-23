#include <math.h>
#include <iostream.h>
float Func (float a,float b);
int main () {
float a,b;
cin>>a>>b;
cout<<Func (a,b);

return 0;
}
float Func (float a, float b) {
return pow (a,b);
}