#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    int sum,c;
    for(int i=100; i<=999; i++) {
        n=i;
        sum=0;
        c = n%10;
        n/=10;
        c*=c;
        sum+=c;
        c = n%10;
        n/=10;
        c*=c;
        sum+=c;
        n*=n;
        sum+=n;
        if(sum%13==0) {out<<i<<" ";}       
    } 
    return 0;    
}