#include <iostream.h>
#include <string.h>
int main () {
    char lex[100];
    char *token;
    cin.getline(lex,100,'\n');
    int count;
    count=strlen(lex);
    //token=strtok(lex,",");
    for (int i=0; lex[i]!=count;i++){
        if ((lex[i]>=48)&&(lex[i]<=57)){
            cout<<lex[i];
            }

        }

return 0;}
