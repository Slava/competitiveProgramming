#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("A.in");
    ofstream fout ("A.out");
int q,K;
int counter=1;
fin>>q>>K;
while (counter<=K){
int A,B,C,D,x1,x2,x;
fin>>A>>B>>C>>D;
if ((A==C)||(A==D)||(B==C)||(B==D))
{
fout<<"Yes"<<endl;
}


if ((A!=C)&&(A!=D)&&(B!=C)&&(B!=D))
{
if (A>B){
x1=A-B;}

if (B>A){
x1=B-A;}


if (C>D){
x2=C-D;}

if (D>C){
x2=D-C;}

x=x1+x2;
if (x>=q){
fout<<"Yes"<<endl;}
if (x<q){
fout<<"No"<<endl;
}}
counter++;
}



    fin.close();
    fout.close();


return 0;
}

