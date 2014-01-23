#include<iostream.h>
int main () {
int i,n;
long long int result=1;
cin>>n;
for (i=2;i<=n;i++){
result*=i;
}

cout<<result;

return 0;
}
