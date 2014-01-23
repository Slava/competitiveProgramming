#include <iostream.h>
int main () {
int b;
cin>>b;

cout<<((b%4==0)&&((b%100!=0)&&(b%400!=0)))?"366":"365");

return 0;
}
