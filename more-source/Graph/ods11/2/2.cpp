#include <iostream>
#include <fstream>
using namespace std;
int main () {
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int N,M;
fin>>N>>M;
//fin>>N>>M;
int a[N];
int c=0,d=0;
for(int i=0;i<N;i++){
 a[i]=0;
}
	for(int i=0;i<M;i++){

		fin>>c>>d;
		//fin>>c>>d;
		a[c-1]++;
		a[d-1]++;
	}

	for(int i=0;i<N;i++){
	fout<<a[i]<<" ";
	//fout<<a[i].vssoed<<" ";
	}

fin.close();
fout.close();
return 0;
}
