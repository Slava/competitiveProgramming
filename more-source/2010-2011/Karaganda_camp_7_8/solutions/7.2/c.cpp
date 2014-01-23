#include<iostream>
using namespace std;

int main() {
    int n,min,temp;
    cin>>n;
    cin>>min;
    for(int i=1; i<n; i++) {
        cin>>temp;
        if(temp<min) min=temp;        
    }
    cout<<min;
    return 0;    
}
