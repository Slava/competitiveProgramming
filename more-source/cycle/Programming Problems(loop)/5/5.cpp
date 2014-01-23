#include <iostream.h>
#include <fstream.h>
int main () {
        ifstream fin ("5.in");
    ofstream fout ("5.out");

int a,b,c,;
fin>>a>>b;

if (b*2<=a){
fout<<"You will lose";}
b++;
c=a-b;

if (a>c){
fout<<"You will win. Start with "<<c;
}

fin.close();
fout.close();


return 0;
}

