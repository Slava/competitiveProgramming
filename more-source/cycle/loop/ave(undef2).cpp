#include <iostream.h>
int main () {
int nrMark,mark,total;
float ave;
//cout<<"Enter first mark [0-100] : ";
//cin>>mark;
total=0;
nrMark=0;
while (mark!=0){
cout<<"Enter next mark [1-100] or 0 to finish : ";
cin>>mark;
total=total+mark;
nrMark++;
}
nrMark--;
ave=(float)total/nrMark;

cout<<"Average is : "<<ave;



return 0;
}
