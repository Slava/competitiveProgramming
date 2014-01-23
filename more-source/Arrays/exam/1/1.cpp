#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
short massive[100];
int i=0;
for (i;i<100;i++){
    fin>>massive[i];
    if (massive[i]==0){
    goto start;}
    }
start:
    fout<<i<<endl;
    for (int j=0;j<i;j++)
    {
        fout<<massive[j]<<" ";
        }

    fin.close();
    fout.close();

return 0;}
