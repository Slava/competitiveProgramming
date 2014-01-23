#include<fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("5.in");
    ofstream fout ("5.out");
int a,d,sum=0;
while (d!=a){
d=a;
fin>>a;

sum=sum+a;
}
fout<<sum;
fin.close();
fout.close();

return 0;
}
