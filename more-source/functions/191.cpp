#include <iostream.h>
void Fuct (int a);
int main () {
int a;
cin>>a;
Fuct (a);

return 0;
}
void Fuct (int a) {
for (int i=1;i<=a;i++){
if (a%i==0)
cout<<i<<" ";
}

}