#include<iostream.h>
#include<fstream.h>
int main () {
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int N;
fin>>N;
int a[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
//		    cin>>a[i][j];
		    fin>>a[i][j];
		    }
	}
int i=0,count=1,l1,l2;
int a1=-1,a2=-1,a3=-1;
while(count>0){
long long int min=999999999;
	        for(int j=0;j<N;j++){
            if((count<3)&&(j==a1)){continue;}
            if ((j!=i)&&(j!=a2)&&(j!=a3)&&(j!=l2)&&(min>a[i][j])){min=a[i][j];l1=i;l2=j;}
            }
	if ((count>3)&&(l2==a1)){goto end;}
        if(count==1){a1=i;a2=l2;i=a2;}
        else{
            if(count==2){a3=l2;i=a3;}
            else{
                a1=a2;
                a2=a3;
                a3=l2;
                i=a3;
                }
            }
count++;
}
end:
fout<<a1+1<<" "<<a2+1<<" "<<a3+1;

fin.close();
fout.close();
return 0;
}
