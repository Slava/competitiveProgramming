#include <fstream.h>
#include <iostream.h>
int dtp;
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
int N;
fin>>N;
int Array [N];
int min=1000000000;
int count=0;

for (int i=0;i<N;i++){
fin>>Array[i];
}
fin>>dtp;
for (int i=0;i<N;i++)
{
    int temp;
temp=dtp-Array[i];
	if (temp<0)
	{
	temp=temp*-1;
	}

	if (temp<min)
	{
	min=temp;
	count=i;
	}

}

fout<<count+1;
    fin.close();
    fout.close();


return 0;
}
