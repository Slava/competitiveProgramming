#include <iostream.h>
#include <fstream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int a,c;
    char b;
    fin>>a>>b>>c;
    switch (b) {
        case '+':
        fout<<a+c<<endl;
        break;
        case '-':
        fout<<a-c<<endl;
        break;
        case '*':
        fout<<a*c<<endl;
        break;
        }
fin.close();
fout.close();
return 0;
}

