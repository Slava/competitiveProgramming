#include<iostream>
using namespace std;

int main() {
    int n,m,min,temp;
    cin>>n>>m;
    cin>>min;
    for(int i=1; i<n*m; i++) {
        cin>>temp;
        if(temp<min) {min=temp;}    
    }
    cout<<min;
    return 0;
}