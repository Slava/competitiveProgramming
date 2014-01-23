#include <fstream.h>
#include <math.h>
int main () {
    ifstream fin ("F.in");
    ofstream fout ("F.out");
long long int A,B,C;
fin>>A>>B>>C;
A=pow(A, B);
C=A%C;
fout<<C;


    fin.close();
    fout.close();


return 0;
}
