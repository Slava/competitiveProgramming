#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    getline(cin,str);
    int c=0;
    string res="";
    while(str.size()>0) {
       if((str[0]-48)>=0 && (str[0]-48)<=9 && (str[1]-48)>=0 && (str[1]-48)<=9) {
          c+=(str[0]-48)*10;
          c+=(str[1]-48);
          for(int j=0; j<c; j++) {
              res+=str.substr(2,1);        
          }
          str = str.substr(3,str.size()-3);                        
       }        
       else if((str[0]-48)>=0 && (str[0]-48)<=9) {
          c+=(str[0]-48);     
          for(int j=0; j<c; j++) {
              res+=str.substr(1,1);        
          }
          str = str.substr(2,str.size()-2);
       }
       else {
            c+=1;
            res+=str.substr(0,1);
            str = str.substr(1,str.size()-1);
       }
       c=0;
    }
    for(int i=1; i<=res.size(); i++) {
        cout<<res[i-1];
        if(i%40==0) {cout<<endl;}        
    }
    return 0;    
}
 
