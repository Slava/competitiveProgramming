#include<iostream>
using namespace std;
int main(){
    
    __int64 a[109][109]={0}, i, j, n, m;
    cin>>n>>m;
    a[1][1]=1;
    for(i=2; i<=n; i++){
             for(j=2; j<=m; j++){
                      if(a[i-1][j-2]>0)a[i][j]+=a[i-1][j-2];
                      if(a[i-2][j-1]>0)a[i][j]+=a[i-2][j-1];
                      }
             }
    cout<<a[n][m];
    cout<<endl;
    for(i=1; i<=n; i++){
             for(j=1; j<=m; j++){
                      cout<<a[i][j]<<" ";
                      }
             cout<<endl;
             }
    return 0;
    }