#include <iostream>
#include <fstream>

using namespace std;


ifstream fin("b.in");
ofstream fout("b.out");


void Stackadd(int a[],int &size,int direc,int number){
    size++;
    if(direc==1){
        for(int i=size;i>0;i--){
            a[i]=a[i-1];
            }
        a[0]=number;
        }
    if(direc==2){

        a[size]=number;}
    }

void Stacktake(int a[],int &size,int direc){
    if(direc==3){
        fout<<a[0]<<endl;
        for(int i=0;i<size;i++){
            a[i]=a[i+1];
            }
        }
    if(direc==4){
        fout<<a[size]<<endl;
        }

    size--;
    }

main () {
    int N;
    fin>>N;
    int a[10000];
    int size=-1;
    int operation;
    int numberbook;

    for(int i=1;i<=N;i++){
        fin>>operation;

        if((operation==1)||(operation==2)){
            fin>>numberbook;
            Stackadd(a,size,operation,numberbook);
            }
        else{
            Stacktake(a,size,operation);
            }

        }

fin.close();
fout.close();
return 0;
}

