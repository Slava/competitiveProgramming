//Example of using strings and functions from <string.h>
#include <iostream>
#include <string>
using namespace std;
int main () {
    char str1[]={"Rule number one : "};
    char str2[]={" don't be afraid! "};
    strcat(str1,str2);
    cout<<str1;
system ("pause");
return 0;
    }
