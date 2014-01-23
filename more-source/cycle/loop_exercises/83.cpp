#include<iostream.h>
int main () {
int a,N,b=2,x=1,c,counter=1;
cin>>a>>N;
c=a;
while (counter<=N){
while (b<=x) {
a=a*c;
b++;
}
cout<<a<<" ";
x++;
counter++;
}


//system ("pause");
return 0;
}
