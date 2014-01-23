#include<iostream.h>
#include<fstream.h>
#include <stdlib.h>
ifstream fin ("b.in");
ofstream fout ("b.out");
int main () {
	int N,M,out=0,temp;
                fin>>M>>N;
        for (int i=1;i<=M;i++){
        	temp=i;
                cycle:
                if(temp!=0)
                if ((temp-N)%10==0){out++;}
                else {
                	if(temp!=0){
			temp/=10;goto cycle;}
                        else{goto endcycle;}
		}
                endcycle:
	}
fout<<out;
//system ("pause");
return 0;
}
//fin.close();
//fout.close();