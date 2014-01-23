#include <iostream.h>
int main () {
int N=1;
float z,sum=0,a;
cin>>a;
while (sum<a){
z=1/N;
sum+=z;
N++;
}

sum-=z;
cout<<N<<" "<<sum;
return 0;
}
