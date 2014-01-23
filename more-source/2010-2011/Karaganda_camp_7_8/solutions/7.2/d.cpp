#include<iostream>
using namespace std;

int main() {
    int n,petya,index;
    cin>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    cin>>petya;
    for(int i=0; i<n; i++) {
        if(petya>a[i]) {index=i+1;break;}
        index=n+1;        
    }
    cout<<index;
    return 0;    
} 
