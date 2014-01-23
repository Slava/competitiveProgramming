#include<iostream.h>
int main () {
int a;
float M;
cin>>a>>M;
switch (a) {
case 1:
cout<<M<<endl;
break;
case 2:
cout<<M/1000000<<endl;
break;
case 3:
cout<<M/1000<<endl;
break;
case 4:
cout<<M*1000<<endl;
break;
case 5:
cout<<M*100<<endl;
break;
}

system ("pause");
return 0;
}
