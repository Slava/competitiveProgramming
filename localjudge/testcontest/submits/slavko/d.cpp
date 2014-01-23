#include <cstdio>
#define file "d"

long long a, b, c, m = 10000000000000007LL;

inline long long mod (long long a){
	return a - a / m * m;
}

long long solve(){
	long long r = 0;
	for (int i = 0; i < 3000; i++)
		for (int j = 0; j < 3000; j++)
			r = mod(mod(mod(i*i) * a) + mod(b*j) + mod(c));
	return r;
}

int main (){
	freopen (file ".in", "r", stdin);
	freopen (file ".out", "w", stdout);
	
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld\n", solve());

}
