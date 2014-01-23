#include <iostream.h>
int main () {
int a;
cin>>a;
if ((a>0)&&(a<10)&&(a%2==1))
cout<<"Positive, one-digit, odd"<<endl;

if ((a>0)&&(a<10)&&(a%2==0))
cout<<"Positive, one-digit, even"<<endl;

if ((a>9)&&(a<100)&&(a%2==1))
cout<<"Positive, two-digit, odd"<<endl;

if ((a>9)&&(a<100)&&(a%2==0))
cout<<"Positive, two-digit, even"<<endl;

if ((a>99)&&(a<1000)&&(a%2==1))
cout<<"Positive, three-digit, odd"<<endl;

if ((a>99)&&(a<1000)&&(a%2==0))
cout<<"Positive, three-digit, even"<<endl;

if ((a>999)&&(a<10000)&&(a%2==1))
cout<<"Positive, four-digit, odd"<<endl;

if ((a>999)&&(a<10000)&&(a%2==0))
cout<<"Positive, four-digit, even"<<endl;


//end of positives-----------------------------


if ((a<0)&&(a>-10)&&(a%2==1))
cout<<"Negative, one-digit, odd"<<endl;

if ((a<0)&&(a>-10)&&(a%2==0))
cout<<"Negative, one-digit, even"<<endl;

if ((a<-9)&&(a>-100)&&(a%2==1))
cout<<"Negative, two-digit, odd"<<endl;

if ((a<-9)&&(a>-100)&&(a%2==0))
cout<<"Negative, two-digit, even"<<endl;

if ((a<-99)&&(a>-1000)&&(a%2==1))
cout<<"Negative, three-digit, odd"<<endl;

if ((a<-99)&&(a>-1000)&&(a%2==0))
cout<<"Negative, three-digit, even"<<endl;

if ((a<-999)&&(a>-10000)&&(a%2==1))
cout<<"Negative, four-digit, odd"<<endl;

if ((a<-999)&&(a>-10000)&&(a%2==0))
cout<<"Negative, four-digit, even"<<endl;

system ("pause");
return 0;
}
