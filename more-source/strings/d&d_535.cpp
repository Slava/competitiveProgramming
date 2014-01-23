#include <iostream.h>
#include <string.h>
void printer(char *,int);
main ()
{
char string[100];
char *tokenPtr;
cin.getline(string,100,'/n');
tokenPtr = strtok(string, " ");
while (tokenPtr != NULL) {
printer(tokenPtr,strlen(tokenPtr));
tokenPtr = strtok(NULL, " ");
}
return 0;
}
void printer(char *token,int N){
    char *bla;
    bla=token;
    for (int i=1;i<N;i++){
    bla++;
    cout<<bla;}
    cout<<token<<"ay"<<" ";
    }
