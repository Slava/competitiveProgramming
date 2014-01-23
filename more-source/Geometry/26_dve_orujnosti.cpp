#include <iostream>
#include <cmath>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double x1,y1,x2,y2,r1,r2,r;
    double line;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    r=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(r1+r2>=r&&r+r2>=r1&&r+r1>=r2)cout<<"YES";
    else cout<<"NO";

    }
