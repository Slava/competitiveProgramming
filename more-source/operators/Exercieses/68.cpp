#include<iostream.h>
int main () {
int a;
float L;
cin>>a>>L;
switch (a) {
case 1:
cout<<L/10<<endl;
break;
case 2:
cout<<L*10<<endl;
break;
case 3:
cout<<L<<endl;
break;
case 4:
cout<<L/1000<<endl;
break;
case 5:
cout<<L/100<<endl;
break;
}

system ("pause");
return 0;
}
