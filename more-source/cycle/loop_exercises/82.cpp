#include<iostream.h>
int main () {
int a,N,b=2,c;
cin>>a>>N;
c=a;
while (b<=N) {
a=a*c;
b++;
}
cout<<a;

//system ("pause");
return 0;
}
