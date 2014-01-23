#include <iostream.h>
int main () {
int a[5];
long long c=100000000;
    cout<<"Enter five numbers --> ";
for (int i=0;i<5;i++){
    cin>>a[i];
    if (a[i]<=c)
    c=a[i];
    }
cout<<"in this arrey "<<c<<" is minimal element"<<endl;

system ("pause");
return 0;
}
