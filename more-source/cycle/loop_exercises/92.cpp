#include <iostream.h>
int main () {
int N,f,c=1,z=1;
float a,sum=0;
cin>>N;
while (z<=N) {

while (c<=z){
f*=c;
c++;
}
a=1/f;
sum+=a;
z++;
}
cout<<sum;
return 0;
}
