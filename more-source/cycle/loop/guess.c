#include<iostream.h>
#include <time.h>
int main () {

int a,c,b;
while (b!=0){
    srand ((unsigned) time (NULL));
int r=rand () % 1001+1;
    cout<<"guess number!"<<endl;
    c=0;
do {
cin>>a;
if (a>r)
cout<<"too large "<<endl;
if (a<r)
cout<<"too small "<<endl;
c++;
}
while (a!=r);
cout<<"you won at "<<c<<" try!";
cout<<"enter 0 to exit, or anykey to try again"<<endl;
cin>>b;
}

return 0;
}
