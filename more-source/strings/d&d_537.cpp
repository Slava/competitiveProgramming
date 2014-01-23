#include <iostream.h>
#include <string.h>
int main () {
    char lex[100];
    cin.getline(lex,100,'\n');
    int count=0;
    char *temp;
    char temp1[100];
    strcpy(temp1,lex);
    temp = strtok(temp1, " ");
    //****************************
    for (int i;temp != NULL;i++) {
    temp = strtok(NULL, " ");
    count++;
    }
    cout<<count;
    char *ptr[100];
    ptr[0] = strtok(lex, " ");
    for (int i=1;ptr[i] != NULL;i++) {
    ptr[i] = strtok(NULL, " ");

    }
    for (int count;count>=0;count--){
        cout<<"bla ";
        cout<<ptr[count]<<endl;
        }
    return 0;
    }
