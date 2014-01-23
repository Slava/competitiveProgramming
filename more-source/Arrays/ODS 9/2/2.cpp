#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,M;
fin>>N>>M;
int Array[N][M];
int min=1000;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){

		fin>>Array[i][j];
			if (Array[i][j]<min)
			{
			min=Array[i][j];
			}
		}
	}
	fout<<min;

    fin.close();
    fout.close();


return 0;
}

