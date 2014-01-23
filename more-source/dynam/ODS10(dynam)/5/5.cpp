#include <iostream.h>
#include <fstream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,M;
fin>>N>>M;
long long a[N][M];
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			fin>>a[i][j];
		}

	}
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if ((i==0)&&(j==0)){continue;}
			if ((i==0)&&(j!=0)){a[i][j]+=a[i][j-1];continue;}
			if ((i!=0)&&(j==0)){a[i][j]+=a[i-1][j];continue;}
			else {if(a[i][j-1]<=a[i-1][j])a[i][j]+=a[i][j-1];else a[i][j]+=a[i-1][j];}
		}

	}
fout<<a[N-1][M-1];

   fin.close();
  fout.close();return 0;
}
