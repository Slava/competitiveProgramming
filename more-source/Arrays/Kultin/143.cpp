#include <iostream.h>
int main () {
int a[5],c=0;
for (int i=0;i<5;i++){
    cout<<"a["<<i+1<<"]-->";
    cin>>a[i];
    cout<<endl;
    if (a[i]!=0)
    c++;
    }
cout<<"in this arrey "<<c<<" not 0 elements"<<endl;

system ("pause");
return 0;
}
