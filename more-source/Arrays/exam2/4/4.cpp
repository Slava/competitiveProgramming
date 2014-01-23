#include <fstream.h>
#include <iostream.h>
int main () {
ifstream fin ("input.txt");
ofstream fout ("output.txt");
    int N;
    fin>>N;
    int a[N][N],b[N][N],c[N][N];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            fin>>a[i][j];
            }
        }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            fin>>b[i][j];
            c[i][j]=a[i][j]+b[i][j];
            }
        }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            fout<<c[i][j]<<" ";
            }
            fout<<endl;
        }
fin.close();
fout.close();
return 0;
}

