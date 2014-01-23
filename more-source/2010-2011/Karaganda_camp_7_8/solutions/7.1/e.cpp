#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int year;
    in>>year;
    if(year%400==0 || (year%100!=0 && year%4==0)) {out<<"YES";}
    else {out<<"NO";}
    return 0;    
} 
