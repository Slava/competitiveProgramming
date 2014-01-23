#include <iostream.h>
int main () {
int a[1000],j,b=-100000;
int counter=0;
cout<<"How much elements in arrey? ";
cin>>j;
for (int i=0;i<j;i++){
        cin>>a[i];
        if (a[i]<b)
            {
            counter++;
            }
            b=a[i];
    }
    if (counter>0){
cout<<"NO! ";
    }
    else
    cout<<"Yes!";

system ("pause");
return 0;
}
