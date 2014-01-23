#include <iostream>
#include <fstream>

using namespace std;

int dfs(int h,bool a[][1000],bool was[],int n){
    was[h]=1;
    int max=-1000;
    bool ok=0;
    for(int i=0;i<n;i++){
        if(a[h][i]==1&&was[i]==0){
            int temp=dfs(i,a,was,n);
            if(temp>max){max=temp;}
            ok=1;
            }
        }
    if(ok==1){
    return max+1;}
    return 0;
    }

void waszero(bool was[],int n ){
    for(int i=0;i<n;i++){was[i]=0;}
    }

main () {
ifstream fin("longpath.in");
ofstream fout("longpath.out");

    int n,m,max=-50000;
    fin>>n>>m;
    bool a[1000][1000];
    bool was[n];
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){a[i][j]=0;was[i]=0;}}

    for(int i=0;i<m;i++){
        int t1,t2;
        fin>>t1>>t2;
        a[t1-1][t2-1]=1;
        }

    for(int i=0;i<n;i++){
    int temp=dfs(i,a,was,n);
    if(temp>max){max=temp;}
    waszero(was,n);
    }

    fout<<max;

fin.close();
fout.close();
return 0;
}
