#include<fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("4.in");
    ofstream fout ("4.out");
int a,d,sum=0;

fin>>a;
while (a!=0){

d=a%10;
sum=sum+d;
a=a/10;
}
fout<<sum;
fin.close();
fout.close();

return 0;
}
