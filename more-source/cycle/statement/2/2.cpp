#include<fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("2.in");
    ofstream fout ("2.out");
int N,a,b;
fin>>N;
fin>>b;
while (N>1){
fin>>a;
if (a<b)
b=a;

N--;}

fout<<b;
fin.close();
fout.close();

return 0;
}
