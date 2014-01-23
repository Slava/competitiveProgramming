#include <iostream.h>
int main () {
int N;
cout<<"Enter number";
cin>>N;

for (int i=1;i<=N;i++)
{
   for (int j=1;j<=i;j++)
        {
        cout<<j<<" ";
        }
cout<<endl;
}
return 0;
}
