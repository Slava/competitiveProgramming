#include<iostream.h>
int main () {
int n1,n2,b;
cin>>n1;
switch (n1) {
case 0:
cout<<"Sever"<<endl;
break;
case 1:
cout<<"Zapad"<<endl;
break;
case -1:
cout<<"Vostok"<<endl;
break;
case 2:
cout<<"Yug"<<endl;
break;
case -2:
cout<<"Yug"<<endl;
break;
}
cin>>n2;
b=n1+n2;
switch (b) {
case 0:
cout<<"Sever"<<endl;
break;
case 4:
cout<<"Sever"<<endl;
break;
case -4:
cout<<"Sever"<<endl;
break;
case 1:
cout<<"Zapad"<<endl;
break;
case -3:
cout<<"Zapad"<<endl;
break;
case -1:
cout<<"Vostok"<<endl;
break;
case 3:
cout<<"Vostok"<<endl;
break;
case 2:
cout<<"Yug"<<endl;
break;
case -2:
cout<<"Yug"<<endl;
break;
}
system ("pause");
return 0;
}
