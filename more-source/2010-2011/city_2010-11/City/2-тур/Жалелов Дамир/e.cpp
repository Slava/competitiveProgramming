#include<iostream>
#include<cstdio>
using namespace std;
int m[30001][260],a,b,n[260][100];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
     cin>>a>>b;
    for(int e=0;e<a;e++)
        for(int i=0;i<b;i++)
            cin>>m[e][i];
    n[a-1][0]=1;
        for(int i=a-1;i>=0;i--)
            for(int j=0;j<b;j++){
                if(m[i][j]!=0){
                    if(m[i-1][j]!=0){
                        n[i-1][j]+=n[i][j];
                        }
                    if(m[i][j+1]!=0){
                        n[i][j+1]+=n[i][j];
                        }
                    }
                }
    if(n[0][b-1]!=0)cout<<n[0][b-1];
    else cout<<"impossible";
    return 0;}


