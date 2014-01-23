#include <fstream>
using namespace std;
ifstream fin ("cube.in");
ofstream fout ("cube.out");
int main()
{	    
	int n,i,a[6],q,k,p,f,b,l,r,u,d;
	fin>>n;
	for (i=0; i<n; i++){
	    fin>>f>>b>>l>>r>>u>>d;
	if (f==l || f==r || f==u || f==d || b==l || b==r || b==u 
             || b==d || l==u || l==d || r==u || r==d)
         {fout<<"yes"<<endl;}
	   else {fout<<"no"<<endl;}}

return 0;
}
