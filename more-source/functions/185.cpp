#include <iostream.h>
//Pi*r^2
int obem (int radius, int height);
int main () {
int radius, height;
cin>>radius>>height;
cout<<obem(radius, height);

return 0;
}
int obem (int radius, int height){
int sum;
radius=radius*radius;
sum=radius*height*3.14;
return sum;
}