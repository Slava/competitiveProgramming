#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N;
fin>>N;
int Arrey[N];
	for(int i=0;i<N;i++)
	{
	fin>>Arrey[i];
	}

	for(int i=0;i<N;i++)
	{
		if (i%2==0)
		{
		fout<<Arrey[i]<<" ";
		}
	}

	for(int i=0;i<N;i++)
	{
		if (i%2==1)
		{
		fout<<Arrey[i]<<" ";
		}
	}

    fin.close();
    fout.close();

return 0;}
