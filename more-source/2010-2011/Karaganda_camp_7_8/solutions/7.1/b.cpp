#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        in>>a[i];        
    }
    for(int i=0; i<n/2; i++) {
        out<<a[i]<<" "<<a[n-1-i]<<" ";        
    }
    if(n%2!=0) {
       out<<a[n/2];
    }
    return 0;    
}