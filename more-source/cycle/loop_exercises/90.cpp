#include <iostream.h>
int main () {
int N,a=1,sum=1;
cin>>N;
while (N>0){
sum*=a;
a++;
N--;
}
cout<<sum;
return 0;
}
