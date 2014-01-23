#include <iostream.h>
#include <fstream.h>
#include <math.h>

long power (int i){
    long sum=1;
    for(int j=0;j<i;j++){
        sum*=2;
        }
    return sum;
    }

main (){
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    long bod,sum=0;
    fin>>bod;
    int z=0,k1=0,k0=0;

    while(bod!=0){
        if (bod%2==1){k1++;}
        if(bod%2==0){k0++;}
        bod=bod/2;
        }
        for(int i=1;i<=k1;i++){
            sum+=power(k1+k0-i);
            }

            fout<<sum;
fin.close();
fout.close();

return 0;
    }
