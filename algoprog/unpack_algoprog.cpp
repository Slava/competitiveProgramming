#include<iostream>
#include <cstdio>
#include<cstring>

using namespace std;

int main () {
freopen("unpack.in","r",stdin);
freopen("unpack.out","w",stdout);
    char a[500];
    cin>>a;
    long long size,z=0,i,j;
    size=strlen(a);


    for(i=0;i<size;i++){
        if(a[i]>47&&a[i]<58){
            if (a[i+1]>47&&a[i+1]<58){
                for(j=0;j<(a[i]-48)*10+a[i+1]-48;j++){
                cout<<a[i+2];z++;if(z%40==0)cout<<endl;
                }
                i+=2;
            }
            else{
            for(j=0;j<a[i]-48;j++){
                cout<<a[i+1];z++;if(z%40==0)cout<<endl;
                }
            i++;
            }}
        else {cout<<a[i];z++;if(z%40==0)cout<<endl;}
        }


    return 0;
    }
