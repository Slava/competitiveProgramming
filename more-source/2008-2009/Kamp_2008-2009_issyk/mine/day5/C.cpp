#include <iostream>
#include <fstream>

using namespace std;

short q[100000]={0},size[100000]={0};
bool was[100000][100000]={0};
int j=0;

int way(bool a[],int N,int start,int finish,int e,int &j,int &size){
    was[start]=1;
    for(int i=0;i<N;i++){
        if((a[start][i]==1)&&(i==finish))size++;q[e][j]=i;size=j+1;return size;
        if((a[start][i]==1)&&(was[e][i]==0))j++;size++;return way(a,N,i,finish,e,size);
        }
    return -1;
    }

main () {
ifstream fin("c.in");
ofstream fout("c.out");

    int N,M;
    cin>>N>>M;
    bool a[N][N];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j]=0;
            }
        }

    for(int i=0;i<M;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        a[temp1-1][temp2-1]=1;
        }

    for(int i=0;i<N;i++){
        way(a,N,start,finish,i,0,size[i]);
        }

fin.close();
fout.close();
return 0;
}
