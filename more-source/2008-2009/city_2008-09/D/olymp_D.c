#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("D.in");
    ofstream fout ("D.out");
int N,A,B;
fin>>N>>A>>B;

N=N-A;
B=B+N;

fout<<B;

    fin.close();
    fout.close();


return 0;
}

