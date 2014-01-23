#include <iostream.h>
int main () {
int bin,counter,sum=0,z,x=0;
cin>>bin;
while (bin>0) {
counter=1;
//************************************************
if (bin%10==1) {
z=1;
if (x!=0)
while (counter<=x){
z*=2;
counter++;
}
if (x==0){
z=1;}
}

//**************************************************
if (bin%10==0){
z=0;
}

//*****************************************************



sum+=z;
bin/=10;
x++;
}
cout<<sum;
return 0;
}
