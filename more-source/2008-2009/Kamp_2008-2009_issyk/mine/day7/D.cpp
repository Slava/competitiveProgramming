#include <iostream>
#include <fstream>

using namespace std;

main () {
ifstream fin("flav.in");
ofstream fout("flav.out");

    int N,K;
    fin>>N>>K;
    int KK=-1;
    int a[N];
    for(int i=0;i<N;i++){a[i]=0;}

    for(int i=1;i<N;i++){
        for(int j=0;j<K;j++){
            KK++;
            if(KK>=N){KK-=N;}
            while(a[KK]==1){
                if(a[KK]==1){KK++;}
                }
            }




        a[KK]=1;
    }
    for(int i=0;i<N;i++){
        //cout<<a[i]<<" ";
        if(a[i]==0){fout<<i+1;break;}
        }

fin.close();
fout.close();
return 0;
}
