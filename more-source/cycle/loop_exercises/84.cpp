#include<iostream.h>
int main () {
int a,N,sum=1,b=2,x=1,c,counter=1;
cin>>a>>N;
c=a;
while (counter<=N){
while (b<=x) {
a=a*c;
b++;
}
sum+=a;
x++;
counter++;
}
cout<<sum;

//system ("pause");
return 0;
}
