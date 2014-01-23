#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    ifstream fin ("4.in");
    ofstream fout ("4.out");
int N;
string first, second;
fin>>N;
while (N>0) {

fin>>first>>second;


if ((first=="A")&&(second=="A"))
fout<<"A 0"<<endl;

if ((first=="B")&&(second=="B"))
fout<<"B 0"<<endl;

if ((first=="0")&&(second=="0"))
fout<<"0"<<endl;

if ((first=="AB")&&(second=="A"))
fout<<"A AB B"<<endl;

if ((first=="A")&&(second=="AB"))
fout<<"A AB"<<endl;

if ((first=="AB")&&(second=="AB"))
fout<<"A AB B"<<endl;


if ((first=="A")&&(second=="B"))
fout<<"A AB B 0"<<endl;

if ((first=="B")&&(second=="A"))
fout<<"A AB B 0"<<endl;

if ((first=="0")&&(second=="A"))
fout<<"A 0"<<endl;

if ((first=="A")&&(second=="0"))
fout<<"A 0"<<endl;

if ((first=="B")&&(second=="0"))
fout<<"B 0"<<endl;

if ((first=="0")&&(second=="B"))
fout<<"B 0"<<endl;

if ((first=="AB")&&(second=="B"))
fout<<"AB B"<<endl;

if ((first=="B")&&(second=="AB"))
fout<<"AB B"<<endl;


N--;
}

fin.close();
fout.close();


return 0;
}
