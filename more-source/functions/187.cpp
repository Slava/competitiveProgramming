#include <iostream.h>
char Func (int a, int b);
int main () {
int a,b;
cin>>a>>b;
cout<<a<<Func (a, b)<<b;

return 0;
}
char Func () {
if (a<b)
return '<';

if (a>b)
return '>';

if (a==b)
return '=';
}