//zaychik
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    int N,K;
    const int size=300;
    fin>>K>>N;
    int a[size]={0};

    a[K-1]=1;

    for(int i=K;i<N+K;i++){
        for (int j=i-1,o=0;o<K;o++,j--){
            a[i]+=a[j];
            }
        }
    fout<<a[N+K-1];

fin.close();
fout.close();
    return 0;
}
