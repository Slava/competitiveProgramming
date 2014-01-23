#include <iostream.h>
int main () {
int N,a,sum=1;
cin>>N;
if (a%2==1)
{a=1;
while (a<=N){
sum*=a;
a+=2;
}}
if (a%2==0){
a=2;
while (a<=N){
sum*=a;
a+=2;
}}

cout<<sum;
return 0;
}
