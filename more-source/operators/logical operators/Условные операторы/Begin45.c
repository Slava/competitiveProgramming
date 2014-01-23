#include <iostream.h>
int main () {
int a,b,c;
cin>>a>>b>>c;
if ((a<b)&&(a<c))
cout<<a<<endl;
if ((b<a)&&(b<c))
cout<<b<<endl;
if ((c<b)&&(c<a))
cout<<c<<endl;
if ((a>b)&&(a>c))
cout<<a<<endl;
if ((b>a)&&(b>c))
cout<<b<<endl;
if ((c>b)&&(c>a))
cout<<c<<endl;
return 0;

}
