#include <iostream.h>
#include <fstream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int arrey[10000];
    int N=0,M=0;
    int n;
    int count;
    int b[10000]={0},d[100],z,x;
    int counter=0;

    for (int i=0;i<10000;i++){
        fin>>n;
            if (n==0){
                goto go1;
                }
        N=N+n;
        for (int j=M;j<N;j++)
        {
            fin>>arrey[j];
        }

b[counter]=M;
d[counter]=N;
        M=N;
        count=i;
counter++;
        }

    go1:
    fout<<count+1<<endl;
for (int i=0;i<count+1;i++){
    for (int z=b[i];z<d[i];z++){
    fout<<arrey[z];
        }

    fout<<endl;
}
   fin.close();
  fout.close();
 return 0;   }
