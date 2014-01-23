#include <iostream>

using namespace std;

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    
    int N;
    int a[20001],b[20001],temp;
    cin>>N;
    
    for (int i=0;i<N;i++){
        cin>>a[i];
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if(a[j]==i+1){temp=j;break;}
        }
        b[i]=temp+1;
    }
    for(int i=0;i<N;i++){
        cout<<b[i]<<" ";
    }
    
return 0;
}