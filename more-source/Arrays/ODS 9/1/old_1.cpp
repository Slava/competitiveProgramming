#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,temp,count=0;
fin>>N;
int Array[N];
//enter the array
	for(int i=0;i<N;i++){
		fin>>Array[i];}
//sort
	for (int i=1;i<N;i++){
		for (int j=0;j<N+1;j++){
			if (Array[j]<Array[j+1]){
			temp=Array[j];
			Array[j]=Array[j+1];
			Array[j+1]=temp;
			}
		}
	}

	while (N!=0){
	    N--;
	    count+=N;

	    }


fout<<count;

fin.close();
fout.close();

}
