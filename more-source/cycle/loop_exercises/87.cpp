#include <iostream.h>
int main () {
int K=1,N,a,c;
a=3*1;
cin>>N;
while (a<N){
a*=3;
K++;
}
a/=3;
K--;
cout<<a<<" "<<K;
return 0;
}
