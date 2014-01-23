#include <fstream>
#include <string>
using namespace std;
int main () {
        ifstream fin ("2.in");
    ofstream fout ("2.out");
int m,n,x;
int z=0;
string s1=" round", s2=" not round";
fin>>m>>n;
x=m;
while (x<=n){
int l=0/*1*/,k=0/*0*/;
m=x;
    while (m!=1){
        if (m%2==1)
        l++;
        if (m%2==0)
        k++;
    m/=2;
}
l++;
if (l<=k)
z++;

if (l<=k){
fout<<x<<" 1x"<<l<<" 0x"<<k<<s1<<endl;
}

if (l>k){
fout<<x<<" 1x"<<l<<" 0x"<<k<<s2<<endl;
}


x++;
}

fout<<z;

fin.close();
fout.close();


return 0;
}
