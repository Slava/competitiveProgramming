#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,counter=1;
int Arrey[N];
int counter2=0;
fin>>N;
	for (int i=0;i<N;i++){
	fin>>Arrey[i];
		if ((Arrey[i]%2==0)&&(counter%2==0))
		{
		counter2++;
		}

	counter++;

	}
fout<<counter2;

    fin.close();
    fout.close();

return 0;}
