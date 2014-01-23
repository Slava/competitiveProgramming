#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int a,b;
    in>>a>>b;
    if(a==0) {out<<"INF";}
    else if(b%a!=0) {out<<"NO";}
    else {
        out<<-b/a;     
    }
    return 0;    
}