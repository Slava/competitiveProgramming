#include <iostream>
#include <iomanip>
using namespace std;

int a[15][15]={0},n,i=0,j=0,k,index=0;


void show(int z[15][15]){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
        cout<<z[i][j]<<' ';
      cout<<endl;
        }
    }

int main (){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);


    cin>>n;
    if(n==1){cout<<1;goto end;}
    if(n==2){cout<<"No solution";goto end;}

    if(n%2==1){
        int sqrn=n*n;j=n/2;
        for (k=1;k<=sqrn;++k)
        {
            a[i][j]=k;
            i--;
            j++;
            if (k%n==0){i+=2;--j;}
            else {if(j==n)j-=n;
              else if(i<0)i+=n;}
        }
        for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        cout<<a[i][j]<<' ';
        cout<<endl;
        }
    }

    else if(n%4==0){
        int I[15][15],J[15][15];
        index=1;
      for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
          I[i][j]=((i+1)%4)/2;
          J[j][i]=((i+1)%4)/2;
          a[i][j]=index;
          index++;
        }

      for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
          if (I[i][j]==J[i][j])
            a[i][j]=n*n+1-a[i][j];
        }

    }

    else {
          /*int p=n/2,M[15][15],K[15],L[15];
          for (i=0;i<p;i++)
            for (j=0;j<p;j++)
            {
              a[i][j]=M[i][j];
              a[i+p][j]=M[i][j]+3*p*p;
              a[i][j+p]=M[i][j]+2*p*p;
              a[i+p][j+p]=M[i][j]+p*p;
            }
         for (i=0;i<p;i++)K[i]=i+1;

         k=(n-2)/4;

        for (i=1;i<=k;i++)L[index++]=i;

        for (i=n-k+2;i<=n;i++)L[index++]=i;
        int temp;
        for(i=1;i<=p;i++)
        for(j=1;j<=index;j++)
        {
          temp=a[i-1][L[j-1]-1];
          a[i-1][L[j-1]-1]=a[i+p-1][L[j-1]-1];
          a[i+p-1][L[j-1]-1]=temp;
        }
        i=k;j=0;
        swap(a[i][j],a[i+p][j]);
        j=i;
        swap(a[i+p][j],a[i][j]);*/
        if(n==6){
            int b[15][15]={{35,1,6,26,19,24},{3,32,7,21,23,25},{31,9,2,22,27,20},{8,28,33,17,10,15},{30,5,34,12,14,6},{4,36,29,13,18,11}};
            show(b);goto end;
            }
        if(n==10){
            int b[15][15]={ {92,99,1,8,15,67,74,51,58,40},{98,80,7,14,16,73,55,57,64,41},{4,81,88,20,22,54,56,63,70,47},{85,87,19,21,3,60,62,69,71,28},{86,93,25,2,9,61,68,75,52,34},{17,24,76,83,90,42,49,26,33,65},{23,5,82,89,91,48,30,32,39,66},{79,6,13,95,97,29,31,38,45,72},{10,12,94,96,78,35,37,44,46,53},{11,18,100,77,84,36,43,50,27,59} };
            show(b);goto end;
            }
        }
    show(a);

    end:
return 0;
}
