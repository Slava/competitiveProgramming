#include <iostream.h>
#include <fstream.h>
#include <string.h>
int main () {
ifstream fin ("input.txt");
ofstream fout ("output.txt");
    char s1[225],s2[225],*tokenPtr;
    int count=0;
    int i=0;
    fin.getline(s2,225,'\n');
    fin.getline(s1,225,'\n');
    int N1=strlen(s1);
    int N2=strlen(s2);
        for (i=0;i<N1;i++){
            for (int j=0;j<N2;j++){
                if (s1[i+j]==s2[j]){
                    if (j==N2-1){
                        count++;
                        }
                }
                else{
                break;}
            }
        }
    fout<<count;

fin.close();
fout.close();
return 0;
}
