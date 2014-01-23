#include <iostream.h>
float Procent (int a,float percent);
int main () {
int a;
float percent;
cin>>a>>percent;
cout<<Procent (a,percent);

return 0;
}
float Procent (int a, float percent) {
percent/=100;
return a*percent;
}