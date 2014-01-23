#include <iostream.h>
float Dohod (int a,float b, int c);
int main () {
int vklad,godovoy,dney;
cin>>vklad>>godovoy>>dney;
cout<<Dohod(vklad,godovoy,dney);

return 0;
}
float Dohod (int a,float b, int c) {
float sum;
b/=100;
sum=a*b*c;
return sum;
}