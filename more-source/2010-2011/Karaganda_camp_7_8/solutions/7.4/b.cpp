#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    int reshka=0;
    int gerb=0;
    for(int i=0; i<n; i++) {
       cin>>k;
       if(k==1) {
          reshka++;
       }
       else if(k==0) {
          gerb++;
       }
    }
    int min = (gerb<reshka)? gerb:reshka;
    cout<<min;
    return 0;
}