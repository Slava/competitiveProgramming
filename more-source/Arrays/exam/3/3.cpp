#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,hold=0;
fin>>N;
int a[N];
for (int i=0;i<N;i++){
fin>>a[i];
}

for (int pass = 1; pass < N; pass++){

 for (int i = 0; i < N - 1; i++)
if (a[i] > a[i + 1]) {
 hold = a[i];
a[i] = a[i + 1];
a[i + 1] = hold;}

}
   for (int i=0;i<N;i++){
        fout<<a[i]<<" ";
        }
   fin.close();
  fout.close();

return 0;}
