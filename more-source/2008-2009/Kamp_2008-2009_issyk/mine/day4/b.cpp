#include <iostream.h>
#include <fstream.h>


template<class T>
T max(T a[],long n) {
    long Max=-1;
    for(int i=0;i<n;i++){
        if(a[i]>Max)Max=a[i];
        }
    return Max;
}


main () {
    ifstream fin ("b.in");
    ofstream fout ("b.out");

    int N;
    fin>>N;
    long a[N];
    int cmd;

    for(int j=0,i=0;j<N;j++,i++){
    fin>>cmd;
    if(cmd==0){fin>>a[i];}
    if(cmd==1){
        fout<<max(a,i)<<" ";
        i=0;
        }
    }

    fin.close();
    fout.close();

    return 0;
    }
