#include <iostream.h>
int main () {
int b,a,N;
cin>>N;
cin>>b;
while (N>1){
cin>>a;
if (a>b){
b=a;}
N--;}
cout<<b;
return 0;
}
