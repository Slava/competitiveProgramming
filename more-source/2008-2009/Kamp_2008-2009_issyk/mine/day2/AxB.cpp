#include <iostream.h>
#include <fstream.h>
#include <math.h>

void SMul(int a[], int &size,int c[],int B) {
long i, temp;
short  carry=0;
for (i=0; i<size;i++) {
temp = a[i]*B + carry;
carry = temp / 10;
c[i] = temp - carry*10; // ñ[i] = temp % BASE
}
if (carry) {
c[i] = carry;
size++;
}
}
main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int size,body[101]={0},t[101]={0};
    int j,i,sec;
    const int strsize=1000;
    char str[strsize];
    fin>>str;
    size=strlen(str);
    for(j=0,i=strlen(str)-1;j<strlen(str),i>=0;j++,i--){
        body[j]=(int)str[i]-48;
        }

    fin>>sec;
SMul(body,size,t,sec);
    for(i=size-1;i>=0;i--){fout<<t[i];}

fin.close();
fout.close();

    return 0;
    }
