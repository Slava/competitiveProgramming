#include<iostream.h>
#include<fstream.h>

int main () {
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int N,sum=0;
fin>>N;
int a[N][N];
int b[N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		    fin>>a[i][j];
		    //fin>>a[i][j];

		    }
	}

    for(int i=0;i<N;i++){
        fin>>b[i];
        //fin>>b[i];
        }

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		    if((a[i][j]==1)&&(b[i]!=b[j])){sum++;}
		    }
	}

fout<<sum/2;
fin.close();
fout.close();
return 0;
}
