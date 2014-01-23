#include<iostream>
#include<cstdio>
using namespace std;
int m[100],n,j,k;
string c;
int main(){
    //ifstream cin("c.in");
    //ofstream cout("c.out");
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d", &n);
    for(int e=0;e<n;e++)
            cin>>c;

    for(int e=1;;e++){
        j=e;
        k=0;
        for(int i=1;j>=1;i++){
            k++;
            m[k]=j%2;
            j/=2;
            }
        if(k<=n){
            for(int i=1;i<=n;i++){
                if(m[i]!=0)
                    //cout<<i<<" ";
                    printf("%d ", i);
                }
            //cout<<endl;
            printf("\n");
            }
        else break;
        }
    return 0;}

