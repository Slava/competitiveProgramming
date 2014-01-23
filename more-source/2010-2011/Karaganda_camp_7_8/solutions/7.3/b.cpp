#include<iostream>
using namespace std;

int main() {
    int n, temp;
    bool t = true;
    int index=1;
    cin>>n;
    int max;
    cin>>max;
    for(int i=1; i<n; i++) {
        cin>>temp;
        if(temp>=max) {max=temp;index=i+1;}
        else {t=false; index = i+1; break;}    
    }
    if(t) {cout<<"OK";}
    else {cout<<index;}
    return 0;    
}