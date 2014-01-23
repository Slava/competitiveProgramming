#include <iostream>
using namespace std;

    int n,m,a[999999],k,l,s=1,w;

main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    while(s<=n){
        for(int i=0;i<n-s+1;i++){
            for(int j=i;j<s+i;j++){
                if(a[j]<m)k++;
                if(a[j]>m)l++;
                }
            if(k==l)w++;
            k=0;l=0;
            }
        s+=2;
        }
    cout<<w;



    }
