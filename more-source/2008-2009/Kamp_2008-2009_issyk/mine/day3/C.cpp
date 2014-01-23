#include <iostream>
#include <fstream>

using namespace std;

int max(long int a,long int b){
    if(a>b)return a;
    else return b;
    }

int min (long int a,long int b){
    if(a<b)return a;
    if(a>b) return b;
    if(a==b)return a;
    }

main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    long int N,M,t1,t2,stol=1;
    long int zakonchil=0,zakazstol,tzakaz;
    long int sum=0,newz=0;

    fin>>N>>t1>>t2>>M;

    for(int i=0;i<M;i++){
        fin>>tzakaz>>zakazstol;
        long int te=max(stol,zakazstol)-min(stol,zakazstol);
        long int te2=((N-stol)+zakazstol);
        long int te3=min(te,te2);
        long int te4=((N+stol)-zakazstol);
        te3=min(te3,te4);
        newz=(t1*te3)+t2;
        if(zakonchil>tzakaz){newz+=(zakonchil-tzakaz);}
        stol=zakazstol;
        sum+=newz;
        zakonchil=newz+tzakaz;
        }

    fout.precision(3);
    fout<<fixed<<(double)sum/M;

    return 0;
}
