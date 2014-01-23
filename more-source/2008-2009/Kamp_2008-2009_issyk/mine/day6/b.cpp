#include <iostream>
#include <fstream>

using namespace std;

main () {
ifstream fin("input.txt");
ofstream fout("output.txt");

//start = 1000, exit 5, prepyzd -1
    int N,exit,temp;
    fin>>N;
    fin>>exit;
    int max=-10001,min=10001;
bool imp=0;

    for(int i=0;i<N;i++){
        fin>>temp;
        if(temp<=0){if(temp>max){max=temp;}}
        if(temp>0){if(temp<min){min=temp;}}
        }
    if((min<exit)||(max>exit)){imp=1;goto impos;}

    if(exit==0){fout<<"0 0";goto end;}
    if(exit<0) {fout<<min*2+exit*-1<<" ";fout<<exit*-1;goto end;}
    if(exit>0) {fout<<exit<<" "<<max*-2+exit;}

impos:
    if(imp==1){fout<<"Impossible";}
end:

fin.close();
fout.close();
return 0;
}
