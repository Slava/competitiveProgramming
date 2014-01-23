#include <iostream>
#include <string>
using namespace std;
main () {
    char s1[100],s2[100];
    cin.getline(s1,100,'\n');
    cout<<"string n1 = "<<s1<<endl;
    cin.getline(s2,100,'\n');
    cout<<"string n2 = "<<s2<<endl;
    cout<<"strncat(s1,s2,5) = "<<strncat(s1,s2,5)<<endl;
    cout<<"strncpy(s2,s1,7) = "<<strncpy(s2,s1,7)<<endl;
return 0;
    }
