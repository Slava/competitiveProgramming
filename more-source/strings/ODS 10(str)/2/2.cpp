#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,M,sum=0;
fin>>N>>M;
int Array[N][M];
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
            fin>>Array[i][j];
		}
	}
	fin>>N;
	for (int i=0;i<N;i++){
	int a,b;
	fin>>a>>b;
	sum+=Array[a-1][b-1];
	Array[a-1][b-1]=0;
	}

fout<<sum;
    fin.close();
    fout.close();


return 0;
}


