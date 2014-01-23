#include <iostream.h>
#include <fstream.h>
int main () {
        ifstream fin ("5.in");
    ofstream fout ("5.out");

int a,b,c,;
fin>>a>>b;

if (a<=(2*b)+1){
while (a>0){
a-=b;
}
a++;
fout<<"You will win, start with "<<c;
}


if (a>(2*b)+1){
fout<<"You will lose";
}
fin.close();
fout.close();


return 0;
}

