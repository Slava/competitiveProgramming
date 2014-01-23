#include<fstream>
#include<math.h>
using namespace std;
struct point
{
       int x,y;
};
int main()
{
    ifstream in("lines.in");
    ofstream out("lines.out");
    int n,cou=0,ab,b,c;
    in>>n;
    point *a=new point [n];
    for(int i=0;i<n;i++){
    in>>a[i].x>>a[i].y;}
    for(int i=0;i<n;i++){
    for(int k=i+1;k<n;k++){
    ab=a[i].y-a[k].y;
    b=a[k].x-a[i].x;
    c=(a[i].x*a[k].y)-(a[k].x*a[i].y);
    for(int j=0;j<n;j++){
    if(j!=i && j!=k){
    if(a[j].x*ab+a[j].y*b+c==0){
    cou++;}}}}}
    out<<cou;
    return 0;
}
