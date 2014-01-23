#include<fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("3.in");
    ofstream fout ("3.out");
int a,d=0,c=0,sum=1;
fin>>a;
while (c<=500){
sum=sum*2;
if (a==sum){
fout<<"Yes";
d++;}
c++;
}
if (d==0)
fout<<"No";
fin.close();
fout.close();

return 0;
}
