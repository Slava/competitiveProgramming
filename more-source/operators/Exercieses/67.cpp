#include <iostream.h>
#include <math.h>
int main () {
int a,c;
char b;
cin>>a>>b>>c;

switch (b) {
case '1':
cout<<a+c<<endl;
break;
case '2':
cout<<a-c<<endl;
break;
case '3':
cout<<a*c<<endl;
break;
case '4':
cout<<a/c<<endl;
break;
}



system ("pause");
return 0;
}
