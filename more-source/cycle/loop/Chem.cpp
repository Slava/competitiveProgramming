#include <iostream.h>
int main () {
  //  ifstream fin ("chem.in");
   // ofstream fout ("chem.out");
int n,weight,quantity,sum=0;
cin>>n;
while (n>0){
cin>>weight>>quantity;
sum=sum+weight*quantity;
n--;
}
cout<<sum;

//fin.close();
//fout.close();

return 0;
}
