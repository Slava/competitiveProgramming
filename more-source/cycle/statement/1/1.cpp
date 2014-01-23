#include<fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("1.in");
    ofstream fout ("1.out");
int a,b,c,d,e,f;
fin>>a>>b>>c>>d;
if ((a%2==1)&&(b%2==1))
e=0;
if ((a%2==0)&&(b%2==0))
e=0;
if ((a%2==1)&&(b%2==0))
e=1;
if ((a%2==0)&&(b%2==1))
e=1;

if ((c%2==1)&&(d%2==1))
f=0;
if ((c%2==0)&&(d%2==0))
f=0;
if ((c%2==1)&&(d%2==0))
f=1;
if ((c%2==0)&&(d%2==1))
f=1;

if (e==f)
fout<<"yes";
if (e!=f)
fout<<"NO";

fin.close();
fout.close();

return 0;
}
