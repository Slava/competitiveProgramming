#include<iostream>
using namespace std;

int main() {
    int c=1,n,counter=0;
    cin>>n;
    while(c<n) {
        c*=2;
        counter++;
    }
    cout<<counter;
    return 0;
}
