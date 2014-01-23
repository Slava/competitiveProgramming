#include <string>
#include <fstream>
#include <iostream>

using namespace std;


main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    char temp[40];
    char *base[10000];
    int counter[10000]={0};
    int i,j,n,min=100001;

    for(i=0;EOF;i++){
        fin>>temp;
        fin>>base[i];
        fin>>temp;
        }

    for(j=0,n=0;j<i;j++,n++){
        if(base[j]!=" ")
            for(int d=j+1;d<i;d++){
                if(strcmp(base[d],base[j])==0)counter[n]++;base[d]=" ";
                }
            base[j]=" ";
        }
    for(j=0;j<n;j++){
        if((min>counter[j])&&(counter[j]!=0))min=counter[j];
        }
    fout<<min;

return 0;
}
