#include<iostream.h>
int main () {
int a,N,sum=1,q,d,c=1;
cin>>a>>N;
q=(2*N)+1;
d=1-a;
while (c<=q){
sum=d*d;
c++;
}
a++;
cout<<sum;
//system ("pause");
return 0;
}
