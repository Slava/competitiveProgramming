#include <fstream.h>
//#include <iostream>
int main () {
ifstream fin ("2.in");
ofstream fout ("2.out");
int a,c;
char b;

fin>>a>>b>>c;
switch (b) {
case '*':
fout<<a*c;
break;
case '-':
fout<<a-c;
break;
case '+':
fout<<a+c;
break;
case '/':
fout<<a/c;
break;
}

return 0;


}
