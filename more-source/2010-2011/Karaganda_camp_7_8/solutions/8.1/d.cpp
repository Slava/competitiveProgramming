#include<iostream>
#include<string>
using namespace std;

int main() {

    string str;
    getline(cin,str);
    int sum=0;
    for(int i=0; i<str.size(); i++) {
        sum+=str[i]-48;        
    }
    if(sum%3==0) {cout<<"YES";}
    else {cout<<"NO";}
    return 0;    
} 
