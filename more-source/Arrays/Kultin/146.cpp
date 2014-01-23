#include <iostream.h>
int main () {
int a[10],non0=0;
float sum=0;
long long c=100000000;
    cout<<"Enter ten numbers --> ";
for (int i=0;i<10;i++){
    cin>>a[i];
    if (a[i]!=0){
        non0++;
        sum+=a[i];
        }}
sum=sum/non0;

cout<<"number of non-zero elements is "<<non0<<endl;
cout<<"average is "<<sum<<endl;

system ("pause");
return 0;
}
