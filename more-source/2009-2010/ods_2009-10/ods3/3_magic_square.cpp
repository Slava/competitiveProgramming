#include <iostream>
using namespace std;

long long int n,a[60][60],col[60]={0},row[60]={0},diag[2]={0};

bool magic(){
    for(int i=1;i<n;i++)if(col[i]!=col[0]){return 0;}
    for(int i=0;i<n;i++)if(row[i]!=col[0]){return 0;}
    if(diag[0]!=diag[1]||diag[0]!=col[0]){;return 0;}
    return 1;
    }

void count(){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            col[j]=row[i]=0;
            diag[0]=diag[1]=0;
        }
    }

        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           col[j]+=a[i][j];
           row[i]+=a[i][j];
           if(i==j){diag[0]+=a[i][j];}
           if((n-i-j)==1){diag[1]+=a[i][j];}
        }
    }
    }

int main ()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cin>>a[i][j];
        }
    }
    count();

    if(magic()==1)cout<<"MAGIC SQUARE";
    else
    {
        long long maxi=-1,mini=99999999,minii[2],maxii[2];
        for(int i=0;i<n;i++){if(col[i]<mini){mini=col[i];minii[0]=i;}if(col[i]>maxi){maxi=col[i];maxii[0]=i;}}
        mini=99999999;maxi=-1;
        for(int i=0;i<n;i++){if(row[i]<mini){mini=row[i];minii[1]=i;}if(row[i]>maxi){maxi=row[i];maxii[1]=i;}}
        mini=min(mini,min(diag[0],diag[1]));

            a[minii[1]][minii[0]]+=(maxi-mini);
            count();
        if(magic()){cout<<"POSSIBLE"<<endl<<minii[1]+1<<" "<<minii[0]+1<<" "<<a[minii[1]][minii[0]];}

        else{
            a[minii[1]][minii[0]]-=(maxi-mini);
            a[maxii[1]][maxii[0]]-=(maxi-mini);
            count();

            if(magic()){cout<<"POSSIBLE"<<endl<<maxii[1]+1<<" "<<maxii[0]+1<<" "<<a[maxii[1]][maxii[0]];}

            else cout<<"NOT POSSIBLE";
        }


    }

    return 0;
}
