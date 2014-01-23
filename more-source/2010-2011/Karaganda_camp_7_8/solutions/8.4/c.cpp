#include<iostream>
using namespace std;
int main(){
    __int64 n, a[209]={1}, i, j;
    a[0]=1;
    cin>>n;
    for(i=1; i<=n; i++){
             for(j=n; j>=i; j--){
                      a[j]+=a[j-i];
                      }
             }
    cout<<a[n];
    return 0;
    }