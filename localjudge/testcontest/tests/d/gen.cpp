#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

long long mod = 10000000000000007LL;

long long solve(long long a, long long b, long long c){
	long long r = 0;
	for (int i = 0; i < 3000; i++)
		for (int j = 0; j < 3000; j++)
			r = ( ((i*i)%mod * a)%mod + (b * j) % mod + c ) % mod;
	return r;
}

string file = "01";
int main (){
	for (int i = 1; i <= 20; i++){
		file[1] = i%10 + '0';
		file[0] = i/10 + '0';
		FILE *out = fopen(file.c_str(), "w");
		long long a, b, c;
		a = rand();b = rand(); c = rand();
		long long ans = solve(a,b,c);
		fprintf(out, "%lld %lld %lld\n", a, b, c);
		fclose(out);
		out = fopen((file + ".a").c_str(), "w");
		fprintf(out, "%lld\n", ans);
		fclose(out);
	}
}


