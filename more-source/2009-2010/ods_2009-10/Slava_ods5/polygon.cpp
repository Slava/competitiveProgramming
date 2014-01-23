#include <iostream>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,x[100100],y[100100],right=0,left=0;
    float m[100000];
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
        if(i>0)m[i]=float(y[i]-y[i-1])/float(x[i]-x[i-1]);
        if(i>1){
            if(m[i]>m[i-1])right++;
            if(m[i]<m[i-1])left++;
            }
    }
    if(n==3)cout<<"YES";
    else{
    if((right>0&&left==0)||(right==0&&left>0))cout<<"YES";
    else cout<<"NO";}

return 0;}
