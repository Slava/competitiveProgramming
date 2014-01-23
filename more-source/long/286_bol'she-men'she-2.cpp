#include <iostream>

using namespace std;

const int m=20006;
void r(short a[][m],long size[],long &sgn);
int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    short A[2][m],B[2][m];long sa[2],sb[2],sgna=0,sgnb=0;
    for(int i=0;i<m;i++)A[0][i]=A[1][i]=B[0][i]=B[1][i]=0;
    r(A,sa,sgna);r(B,sb,sgnb);
    bool minus=0;
    if(sgna>sgnb){printf("<");exit(0);}
    if(sgna<sgnb){printf(">");exit(0);}
    if(sgna&&sgnb)minus=1;

    if(sa[0]>sb[0]){(minus)?printf("<"):printf(">");exit(0);}
    if(sa[0]<sb[0]){(minus)?printf(">"):printf("<");exit(0);}
    for(int i=0;i<sa[0];i++)
        if(A[0][i]>B[0][i]){(minus)?printf("<"):printf(">");exit(0);}
    else if(A[0][i]<B[0][i]){(minus)?printf(">"):printf("<");exit(0);}

    for(int i=0;i<max(sa[1],sb[1]);i++)
        if(A[1][i]>B[1][i]){(minus)?printf("<"):printf(">");exit(0);}
    else if(A[1][i]<B[1][i]){(minus)?printf(">"):printf("<");exit(0);}
    printf("=");


}
void r(short a[][m],long size[],long &sgn)
{
    char c[m];
    bool t=0;int j=0,len;
    cin>>c;len=strlen(c);
    for(int i=0;i<len;i++)
    {
        if(c[i]=='-')sgn=1;
        else if(c[i]=='.'){t=1;size[0]=j;j=0;}
        else {a[t][j]=c[i]-48;j++;}
    }
    size[t]=j;
}

