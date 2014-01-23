#include<iostream>
using namespace std;
int a[100000];

int main() {
    int k,n;
    cin>>k>>n;
    int counter=0;
    while(n>0) {
        a[counter++]=n%k;
        n/=k;          
    }
    for(int i=counter-1;i>=0; i--) {
        cout<<a[i];        
    }
    return 0;    
} 
