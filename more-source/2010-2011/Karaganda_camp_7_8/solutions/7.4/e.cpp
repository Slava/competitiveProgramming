#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "qwertyuiopasdfghjklzxcvbnmq";
    char c;
    cin>>c;
    for(int i=0; i<str.size()-1; i++) {
        if(c==str[i]) {
           cout<<str[i+1];
           break;
        }
    }
    return 0;
}