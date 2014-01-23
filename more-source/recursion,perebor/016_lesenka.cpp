#include <iostream>

using namespace std;

int lesenka(int N,int min){
    int sum=0;
    for (int i=min;i<=N;i++){
        if(i==N){sum++;continue;}
        sum+=lesenka(N-i,i+1);
    }

    return sum;
}

main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    cout<<lesenka(N,1);
    cin>>N;
return 0;
}
