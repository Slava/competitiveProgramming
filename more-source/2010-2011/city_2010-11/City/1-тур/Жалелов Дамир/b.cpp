#include<iostream>
#include<cstdio>
using namespace std;
int m[30001][260],a,b,n[260];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>a>>b;
    for(int e=0;e<a;e++)
        for(int i=0;i<b;i++)
            cin>>m[e][i];

    for(int e=0;e<a;e++)
        for(int i=0;i<b;i++)
            n[m[e][i]]++;
    for(int e=1;e<=250;e++)
        if(n[e]>=a){cout<<e;break;}
    return 0;}
