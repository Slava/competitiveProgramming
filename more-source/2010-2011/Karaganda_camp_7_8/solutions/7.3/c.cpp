#include<iostream>
using namespace std;

int main() {
    int n,next,temp,counter=0;
    cin>>n;
    cin>>next;
    for(int i=1; i<n; i++) {
        cin>>temp;
        if(next==temp) {counter++;}        
        next=temp;
    }
    cout<<counter;
    return 0;    
}