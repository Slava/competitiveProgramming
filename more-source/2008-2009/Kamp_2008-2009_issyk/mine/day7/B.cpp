#include <iostream>
#include <fstream>

using namespace std;

template <class T>
int binary (T b[], long low, int high, int size,long searchkey){
    int middle;
    while(low<=high){
        middle=(low+high)/2;
        if (searchkey==b[middle]){
            for(int i=middle;i<=high;i++){
                if(b[i]==b[middle]){middle=i;}
                }
        return middle;
        }

        else{ if(searchkey<b[middle])
                high = middle-1;
             else low=middle+1;}

        }
    return -1;
    }

main () {
ifstream fin("binary.in");
ofstream fout("binary.out");

    long N,M;
    fin>>N>>M;
    long a[N];
    for(int i=0;i<N;i++){fin>>a[i];}
    for(int i=0;i<M;i++){
        int temp;
        fin>>temp;
        fout<<binary(a,0,N-1,N,temp)+1<<" ";
        }

fin.close();
fout.close();
return 0;
}
