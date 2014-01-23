#include<iostream>
#include<cstdio>
using namespace std;
int b[999999],k,p,o,a[9999][9999],n,m;
main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
cin>>n>>m;
for(int z=0;z<n;z++)
    for(int x=0;x<m;x++)
    cin>>a[z][x];
for(int z=0;z<n;z++)
    for(int x=0;x<m;o++,x++)
        b[a[z][x]]++;
k=b[0];
for(int h=0;h<o;h++)
    if(b[h]>k){k=b[h];p=h;}
    cout<<p;
    }

