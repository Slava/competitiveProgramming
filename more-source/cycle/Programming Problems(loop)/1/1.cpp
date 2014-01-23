#include <iostream.h>
#include <fstream>
using namespace std;
int main () {
    ifstream fin ("1.in");
    ofstream fout ("1.out");
int a,d;
int counter2=1,q,p;
int number1,number2;
int k,l;
fin>>d>>a;
while (counter2<=30) {
//**********************
int counter=1,z=1;

//***********************************************************
int c,i=1,g1=2,g2=2;
number1=0;
number2=0;
q=0;
p=0;

c=a;
for (i=1;i<=d;i++)
{
z*=10;
}
number1=c/z;
c=number1*z;
number2=a-c;
k=number1;
l=number2;
while (g1<=20)
{
if (g1==number1){
continue;}

if (number1==g1){
continue;}

if (number1%g1==0){
q=q+1;}
g1++;
}

while (g2<=20)
{
if (g2==number2){
continue;}

if (number2==g2){
continue;}

if (number2%g2==0){
p=p+1;}
g2++;}


if ((q==0)&&(p==0)){
z*=10;}
//*****************************************************************


//**********************
if ((q==0)&&(p==0)){
break;}

a++;
counter2++;
}
fout<<k<<" "<<l;
fin.close();
fout.close();


return 0;
}

