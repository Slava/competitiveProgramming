#include<iostream.h>
#include<fstream.h>
int main () {
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int N,res=0;
fin>>N;
int a[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		fin>>a[i][j];
		if(a[i][j]==1){res+=1;}
		}
	}
fout<<res/2;


fin.close();
fout.close();
return 0;
}
