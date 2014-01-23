#include <iostream>
#include <fstream>

using namespace std;

main () {
ifstream fin("bigsort.in");
ofstream fout("bigsort.out");

    long long N,temp;
    fin>>N;
    long long b[100]={0};
    for(int i=0;i<N;i++){
        fin>>temp;
        b[temp-1]++;
        }
    for(int i=0;i<100;i++){
        for(int j=0;j<b[i];j++){
            fout<<i+1<<" ";
            }
        }


fin.close();
fout.close();
return 0;
}
