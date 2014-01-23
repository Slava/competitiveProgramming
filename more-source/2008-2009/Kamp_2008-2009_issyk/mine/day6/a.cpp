#include <iostream>
#include <fstream>

using namespace std;

template <class T>
int binary (T b[], long low, int high, int size,long searchkey){
    int middle;
    while(low<=high){
        middle=(low+high)/2;
        if (searchkey==b[middle]){return 1;}

        else{ if(searchkey<b[middle])
                high = middle-1;
             else low=middle+1;}

        }
    return 0;
    }

main () {
ifstream fin("input.txt");
ofstream fout("output.txt");

    int N1,N2;
    fin>>N1;
    int a[N1];
    bool z=0;
    for(int i=0;i<N1;i++){fin>>a[i];}
    fin>>N2;
    int b[N2];
    for(int i=0;i<N2;i++){fin>>b[i];}

    for(int i=0;i<N2;i++){
        if(binary(a,0,N1-1,N1,10000-b[i])==1){z=1;break;}
        }
if(z==0){fout<<"NO";}
if(z==1){fout<<"YES";}

fin.close();
fout.close();
return 0;
}
