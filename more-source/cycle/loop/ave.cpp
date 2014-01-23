#include <iostream.h>
int main () {
int counter=1;
int sum =0;
int a,mark;
float ave;
cout<<"How many marks?";
cin>>a;
while (counter<=a) {
    cout<<"Enter mark";
cin>>mark;
    sum=sum+mark;
counter++;
}

ave = (float) sum/a;
cout<<"Average is:"<<ave;



return 0;
}
