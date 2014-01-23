#include <iostream.h>
void Func (char massive[]);
int main () {
int massive [300];
cin>>massive;
Func (massive []);
return 0;
}
void Func (char massive []) {
for (int i=0;i<300;i++)
{
cout<<toupper(massive [i]);
}
}
