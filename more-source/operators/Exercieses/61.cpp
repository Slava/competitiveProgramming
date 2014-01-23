#include <iostream.h>
int main () {
int a;
cin>>a;
if ((a>0)&&(a<10))
cout<<"Positive, one-digit"<<endl;

if ((a>9)&&(a<100))
cout<<"Positive, two-digit"<<endl;

if ((a>99)&&(a<1000))
cout<<"Positive, three-digit"<<endl;

if ((a<0)&&(a>-10))
cout<<"Negative, one-digit"<<endl;

if ((a<-9)&&(a>-100))
cout<<"Negative, two-digit"<<endl;

if ((a<-99)&&(a>-1000))
cout<<"Negative, three-digit"<<endl;

system ("pause");
return 0;
}
