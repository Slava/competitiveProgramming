#include<iostream>
using namespace std;

int main() {
    int n,counter=0;
    cin>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
       cin>>a[i];        
    }
    
    for(int i=1; i<n-1; i++) {
        if(a[i]>a[i-1] && a[i]>a[i+1]) counter++;        
    }
    cout<<counter;
    return 0;    
} 
