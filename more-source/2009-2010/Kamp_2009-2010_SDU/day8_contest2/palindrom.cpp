#include <iostream>

using namespace std;

bool a[1000][100009];
long n;
char s1[100009];

bool l(long i,long j)
{
    if(j>i&&j>0&&i>=0&&i<n-1&&j<n)return (s1[i]==s1[j]);
    return 1;
}

int main()
{
    cin>>s1;
    long sum = 0,i,j;
    n = strlen(s1);
    for(i=n-2;i>=0;i--)
        for(j=n-1;j>=i+1;j--)
            {a[i%1000][j]=( (s1[i]==s1[j])&&l(i+1,j-1) );sum+=a[i%1000][j];}


    cout<<sum;
    return 0;
}
