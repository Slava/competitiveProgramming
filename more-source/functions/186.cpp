#include <iostream.h>
//Pi*r^2
int max (int a, int b);
int main () {
int a,b;
cin<<a<<b;
cout<<max(a, b);
return 0;
}
int max (int a, int b){
if (a<b)
return b;

if (b<a)
return a;
}