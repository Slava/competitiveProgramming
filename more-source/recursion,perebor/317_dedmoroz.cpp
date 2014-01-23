//dead moroz
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    int X,Y,Z,W,sum=0;
    fin>>X>>Y>>Z>>W;

int temp_X,temp_Y,temp_Z;
    for (int i=0;i<=W/X;i++){
        for (int j=0;j<=(W-(temp_X=X*i))/Y;j++){
            temp_Y=Y*j;
            temp_Z=W-(temp_X+temp_Y);
            if(temp_Z%Z==0){sum++;}
            }
        }

fout<<sum;


fin.close();
fout.close();
    return 0;
}
