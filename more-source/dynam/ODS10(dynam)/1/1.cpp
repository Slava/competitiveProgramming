#include <iostream.h>
#include <fstream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");


char a[10000]={'\0'};
bool b=0;
fin.get(a,10000);
int N=strlen(a);
    for (int i=0;i<N;i++){
        if ((a[i]=='1')&&(a[i+1]=='5')&&(a[i+2]=='4')&&(a[i+3]=='3'))
            {b=1;
            goto end;}
        }
    fout<<"NO";
end:
    if (b==1){
    fout<<"URA";
    }
fin.close();
fout.close();
return 0;
}
