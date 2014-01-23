#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("A.in");
ofstream fout("A.out");
int n , k , a , b = 0 , i;
int main()
{
string q;
fin >> k >> n >> q;
a = q.length();
for(i = 0; i < a; i++)
{
    if(q[i] - 48 > 9 )
    {
        b = (b * k + ((q[i]-64) + 9 ) ) % n;
    }
    else
    {
        b = ( b * k + (q[i] - 48)) % n;
    }
}
fout<<b;
    return 0;
}
