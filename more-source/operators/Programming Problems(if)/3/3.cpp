#include <fstream.h>
#include <iostream.h>
ifstream fin ("3.in");
ofstream fout ("3.out");
int main () {
char a,b,c,d;
fin>>a>>b>>c>>d;
if (((a>64)&&(a<91))||((a>96)&&(a<123)))
fout<<"letter"<<endl;

if ((a>32)&&(a<48))
fout<<"punctuation mark"<<endl;
if ((a>71)&&(a<65))
fout<<"special charecter"<<endl;


if ((a>47)&&(a<58))
fout<<"digit"<<endl;


if (((b>64)&&(b<91))||((b>96)&&(b<123)))
fout<<"letter"<<endl;

if ((b>32)&&(b<48))
fout<<"punctuation mark"<<endl;

if ((b>71)&&(b<65))
fout<<"special charecter"<<endl;

if ((b>47)&&(b<58))
fout<<"digit"<<endl;


if (((c>64)&&(c<91))||((c>96)&&(c<123)))
fout<<"letter"<<endl;

if ((c>32)&&(c<48))
fout<<"punctuation mark"<<endl;

if ((c>71)&&(c<65))
fout<<"special charecter"<<endl;

if ((c>47)&&(c<58))
fout<<"digit"<<endl;


if (((d>64)&&(d<91))||((d>96)&&(d<123)))
fout<<"letter"<<endl;

if ((d>32)&&(d<48))
fout<<"punctuation mark"<<endl;

if ((d>71)&&(d<65))
fout<<"special charecter"<<endl;

if ((d>47)&&(d<58))
fout<<"digit"<<endl;




return 0;
}
