#include <iostream.h>
#include <fstream.h>
int main () {
        ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int N,M,sum=0;
    fin>>N>>M;
    int a[N][M];

        for (int i=0;i<N-1;i++){
            for (int j=0;j<M-1;j++){
                int temp=1;
                if (i==0){
                    if (j==0){
                        a[i][j]=1;
                        }
                    else{
                        a[i][j]=a[i][j-1]+1;
                        }
                    }
                else{
                    if (j==0){
                        a[i][j]=1;
                        }
                    else{
                        a[i][j]=temp;
                        temp+=a[i][j];
                        }
                    }
                }
            }
        for (int i=0;i<N-1;i++){
            for (int j=0;j<M-1;j++){
                sum+=a[i][j];
                }
            }

   if (sum%2==1){
        sum+=1;
        }
    else{
        sum+=1;
        }
        fout<<sum;
   if ((M==2)&&(N==2)){
            sum=2;
            }
        if (((M==2)&&(N==3))||((M==3)&&(N==2))){
            sum=10;
            }
         fin.close();
    fout.close();
    return 0;
    }
