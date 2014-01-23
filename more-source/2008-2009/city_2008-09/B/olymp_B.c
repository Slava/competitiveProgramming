#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("B.in");
    ofstream fout ("B.out");
int N,counter=1;
fin>>N;

while (counter<=N){
int a,counterofdiv=0,hz=1;
fin>>a;
while (hz<=a){
if (a%hz==0){
counterofdiv++;
}


hz++;
}
if (hz%2==0)
fout<<"0 ";

if (hz%2==1)
fout<<"1 ";


counter++;
}



    fin.close();
    fout.close();


return 0;
}

