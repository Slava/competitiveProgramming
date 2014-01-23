#include<iostream.h>
#include<fstream.h>
ifstream fin("c.in");
ofstream fout("c.out");
int Func(int N,int first);
int main () {
  int N;
  fin>>N;
  fout<<Func(N,1);

return 0;
}
int Func(int N,int first){
int factorial=0;
	for(int i=1;i<=first;i++){
        factorial+=i;

	}
if((N-factorial==0)||(N-factorial==1))return 1;
else{
if(factorial==1){
return 1+Func(N,first+1);
}
else return (N-factorial-1)+Func(N,first+1);
}
}