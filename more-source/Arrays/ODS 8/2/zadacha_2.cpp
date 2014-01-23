#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
short Arrey[2];
short a,b;
fin>>Arrey[0]>>Arrey[1];
	while ((Arrey[1]!=0)&&(Arrey[0]!=0)) {
	if (Arrey[0]<Arrey[1])
		{
        b=Arrey[1];
		Arrey[1]=Arrey[1]-Arrey[0];

		}
	else
		{
        a=Arrey[0];
		Arrey[0]=Arrey[0]-Arrey[1];
		}

	}

if (a<b)
{
fout<<a;
}

else
{
fout<<b;
}


    fin.close();
    fout.close();

return 0;}
