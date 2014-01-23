#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,sum1=0,sum=0;
fin>>N;
int Array [N][N];
for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
		fin>>Array[i][j];
		}
	}
for (int i=0;i<N;i++){
sum1+=Array[i][i];
}
for (int i=0;i<N;i++){
sum+=Array[i][N-(i+1)];
}
	fout<<sum1<<" "<<sum;

fin.close();
fout.close();

}
