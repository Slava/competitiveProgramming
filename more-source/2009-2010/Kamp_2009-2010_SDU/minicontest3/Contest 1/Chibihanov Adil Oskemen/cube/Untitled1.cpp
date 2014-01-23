#include<fstream>
using namespace std;
int main()
{
    ifstream in("cube.in");
    ofstream out("cube.out");
    int n;
    in>>n;
    int q,w,e,r,t,y;
    for(int i=0;i<n;i++){
    in>>q>>w>>e>>r>>t>>y;
    if(q==e || q==r || q==t || q==y){
    out<<"YES"<<endl;}
    else if(w==e || w==r || w==t || w==y){
    out<<"YES"<<endl;}
    else if(e==t || e==y){
    out<<"YES"<<endl;}
    else if(r==t || r==y){
    out<<"YES"<<endl;}
    else if((q==e && q==t) || (q==e && q==y) || (w==e && w==t) || (w==e && w==y) || (q==r && q==y) || (q==r && q==y) || (w==r && w==y) || (w==r && w==y)){
    out<<"YES"<<endl;}
    else{
    out<<"NO"<<endl;}}
    return 0;
}
