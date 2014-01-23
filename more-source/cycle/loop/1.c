#include<iostream.h>
int main () {
long long int x1=1,x2=1,n,r,i;
cin>>n;
for (i=3;i<=n;i++){
r=x2;
x2+=x1;
x1=r;
}
cout<<x2;
return 0;
}
