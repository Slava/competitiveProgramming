#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;
    getline(in,s);
    out<<s;
    return 0;    
}