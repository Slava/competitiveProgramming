#include<iostream>
using namespace std;

int main() {
    long long int n;
    cin>>n;
    int c;
    int sum=0;
    while(n>0) {
        c=n%10;
        sum+=c;
        n/=10;       
    }
    cout<<sum;
    return 0;    
} 
