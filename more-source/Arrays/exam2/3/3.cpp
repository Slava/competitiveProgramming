#include <fstream.h>
#include <iostream.h>
int main () {
ifstream fin ("input.txt");
ofstream fout ("output.txt");
    long long int N;
    fin>>N;
    long long int a[N][N];
    a[0][0]=1;
    a[1][0]=1;
    a[1][1]=1;
    for (int i=0;i<N;i++){
        for (int j=0;j<=i;j++){
            a[i][j]=1;
            }
        }
    for (int i=2;i<N;i++){
            for (int j=1;j<i;j++){
                if (j==0){
                    a[i][j]=1;
                    break;
                    }
                if (j==i){
                    a[i][j]=1;
                    break;
                    }
                else{
                    a[i][j]=(a[i-1][j-1]+a[i-1][j]);
                    }
                }
        }
    for (int i=0;i<N;i++){
        for (int j=0;j<=i;j++){
            fout<<a[i][j]<<" ";
            }
            fout<<endl;
        }

fin.close();
fout.close();
return 0;
}
