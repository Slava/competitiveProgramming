#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,M,sum=0;
fin>>N>>M;
int Array[N][M];
int x=0,y=0;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
            fin>>Array[i][j];
		}
	}
	int temp;
	fin>>temp;
	sum+=Array[x][y];
	Array[x][y]=0;
	for (int i=2;i<=temp;i++){
	int a;
	fin>>a;
	switch (a){
	    case 1:
	    y++;
	    break;
	    case 2:
	    x--;
	    break;
	    case 3:
	    y--;
	    break;
	    case 4:
	    x++;
	    }
	    if (x<0){
	        x==0;
	        }
        if (y<0){
            y==0;
            }
	    if (x>=N){
	        x==N-1;
	        }
        if (y>=M){
            y==M-1;
            }
	sum+=Array[x][y];
	Array[x][y]=0;
	}

fout<<sum;
    fin.close();
    fout.close();


return 0;
}


