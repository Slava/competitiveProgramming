#include <cmath>
#include <iostream>
using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

//long long a[1001];

bool p(long long sum,int j)
{
    if(j==9)return 0;
    double ii=sqrt(sqrt(sum+.0));
    long i=(long)ii;
    while(i*i*i<sum)i++;
    for(;i>=0;i--)
    {
        if(i*i*i==sum){cout<<i<<' ';return 1;}
        if(sum>i*i*i&&p(sum-i*i*i,j+1)){cout<<i<<' ';return 1;}
    }
    return 0;
}

int main()
{
    long long n;
    cin>>n;
    bool I=p(n,1);
  //  for(int i=1;i<1001;i++)a[i]=i*i*i;
    if(!I)cout<<"IMPOSSIBLE";
}
