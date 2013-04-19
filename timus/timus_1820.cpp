#include <iostream>
using namespace std;
int main()
{
	int N,K;
	cin>>N>>K;
	if(K>N) N=K;
	N=2*N;
	if((N%K)==0) cout<<N/K;
	else cout<<(N/K)+1;
}
