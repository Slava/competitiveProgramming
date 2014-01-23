#include <iostream.h>
int main () {
int a[5];
int c,i=0,d=100000000;
    cout<<"Enter five numbers --> ";
for (i;i<5;i++){
    cin>>a[i];
    if (a[i]<=d){
    c=i;}
    }
cout<<"in this arrey "<<a[c]<<" is minimal element"<<endl;

system ("pause");
return 0;
}
