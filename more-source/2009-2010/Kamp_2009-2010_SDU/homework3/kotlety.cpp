#include <fstream>

using namespace std;

long a[209][209];
long lesenka(int N,int min){
    long sum=0;
    for (int i=min;i<=N;i++){
        if(i==N){sum++;continue;}
        if(!a[N-1][i+1])a[N-1][i+1]=lesenka(N-i,i+1);
        sum+=a[N-1][i+1];
        }

    return sum;
}
int main (){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N;
    cin>>N;
    cout<<lesenka(N,1);

return 0;
}
