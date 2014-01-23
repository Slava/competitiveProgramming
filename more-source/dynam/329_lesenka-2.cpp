#include <fstream>
using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

   long N,a[1020]={0},c[1020]={0};
   bool b[1020]={0};

int main()
{
   fin>>N;
   for(int i=2;i<N+2;i++)fin>>a[i];

   for(int i=2;i<N+2;i++)
       c[i]=max(a[i]+c[i-1],a[i]+c[i-2]);

    fout<<c[N+1]<<endl;

    for(int i=N+1;i>1;)
    {
        b[i]=1;
        if(c[i-1]+a[i]==c[i])i--;
        else i-=2;
    }

    for(int i=2;i<N+2;i++)
        if(b[i])fout<<i-1<<' ';

	}
