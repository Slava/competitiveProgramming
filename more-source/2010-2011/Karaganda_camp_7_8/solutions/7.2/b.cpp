#include<iostream>
using namespace std;

void func(int n) {
     int counter=1;
     int c=1;
     for(int i=1; i<=1000000; i++) {
        for(int j=1; j<=i; j++) {
            if(c>n) {return;}
            cout<<counter<<" ";    
            c++;
        }        
        counter++;
     }
}

int main() {
    int n;
    cin>>n;
    func(n);
    return 0;    
} 
