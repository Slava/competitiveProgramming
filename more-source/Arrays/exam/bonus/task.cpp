#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,hold=0,counter=1;
fin>>N;
long long a[N];
long long c=-10000000;
for (int i=0;i<N;i++){
fin>>a[i];
}
for (int j=1;j<=3;j++){
for (int i=0;i<N;i++){
    fin>>a[i];
    if (a[i]>=c)
    c=a[i];
}
fout<<c<<endl;
for (int i=0;i<N;i++){
    if (a[i]==c){
        a[i]=-1000000000;
        }

    }
     c=-1000000000;
}


   fin.close();
  fout.close();

return 0;}
