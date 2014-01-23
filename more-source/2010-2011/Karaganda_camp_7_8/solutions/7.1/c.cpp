#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int x1,y1,x2,y2,x,y;
    in>>x1>>y1>>x2>>y2>>x>>y;
    
    if((x>=x1&&x<=x2)&&(y<=y1&&y>=y2)) {out<<"Yes";}
    else {out<<"No";}
    return 0;    
} 
