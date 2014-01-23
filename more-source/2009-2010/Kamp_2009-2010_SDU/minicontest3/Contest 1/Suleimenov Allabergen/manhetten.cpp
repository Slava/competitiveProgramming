#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
ifstream fin ("A.in");
ofstream fout ("A.out");
int main()
{
    
    int n,i,j,b,p,w,c;
    long long d=1000000000;
    vector <int> a;
    fin>>n;
    a.resize(n*2);
    for (i=0; i<n*2; i+=2)
    {fin>>a[i]>>a[i+1];}
    for (i=0; i<n*2; i+=2)
    {
        for (w=1, j=0; j<n*2; j+=2, w++)
        {
          c=abs(a[i]-a[j])+abs(a[i+1]-a[j+1]);
          if (i==j) continue;
          else {}
          if (c<d){
              d=c;
              p=w;
          }
          else if (c==d) {c=c;}
        }
        fout<<p<<" ";
        d=1000000000;
    }
    
    fin.close();
    fout.close();
    return 0;
}
