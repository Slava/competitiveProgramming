#include <iostream.h>
int main () {
long long N;
cin>>N;
for (long long i=1;i<=N;i++)
{
   int sum=0;
        for (long long j=1;j<i;j++)
        {
            if (i%j==0)
            sum+=j;
        }
if (sum==i)
cout<<i<<" ";
}


return 0;
}
