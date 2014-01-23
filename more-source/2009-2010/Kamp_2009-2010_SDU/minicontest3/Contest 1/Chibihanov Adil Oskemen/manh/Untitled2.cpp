#include<fstream>
#include<math.h>
using namespace std;
struct point
{
       int x,y;
};
int main()
{
    ifstream in("A.in");
    ofstream out("A.out");
    int n,min=99999,s=0,it=0;
    in>>n;
    point *a=new point [n];
    for(int i=0;i<n;i++){
    in>>a[i].x>>a[i].y;}
    for(int i=0;i<n;i++){
    min=99999;
    s=0;
    for(int j=0;j<n;j++){
    if(i!=j){
    s=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
    if(s<min){
    min=s;
    it=j+1;}}}
    out<<it<<" ";}
    return 0;
}
