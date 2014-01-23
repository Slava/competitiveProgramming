#include<iostream>
using namespace std;

int main() {
    int a[4];
    int b[4];
    int aa=0,bb=0;
    for(int i=0; i<4; i++) {
        cin>>a[i]>>b[i];
        aa+=a[i];
        bb+=b[i];
    }
    if(aa>bb) {
       cout<<"1";
    }
    else if(aa<bb) {
       cout<<"2";
    }
    else {
       cout<<"DRAW";
    }
    return 0;
}