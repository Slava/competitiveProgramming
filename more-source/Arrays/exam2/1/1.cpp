#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N,M;
    int q=0,p=0;
    fin>>N>>M;
    int a[N][M];
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            fin>>a[i][j];
                if (a[i][j]==0){
                q=j;
                p=i;
                }
            }
        }
    fout<<p+1<<" "<<q+1;

fin.close();
fout.close();
return 0;
}
