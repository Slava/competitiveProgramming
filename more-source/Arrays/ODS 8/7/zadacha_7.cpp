#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N,counter=0;
fin>>N;
int Arrey[N];
int a,b;
	for(int i=0;i<N;i++)
	{
	fin>>Arrey[i];
	}






		for (int i=0;i<N;i++)
		{
			for (int j=i+1;j<N;j++)
			{
			    a=Arrey[i];
			    b=Arrey[j];
				if (a==b)
				{
				counter++;

				}


			}


		}

fout<<counter;

    fin.close();
    fout.close();

return 0;
}
