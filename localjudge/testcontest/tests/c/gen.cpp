#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

string s = "01";
int main (){
	FILE *out;
	for (int i = 1; i <= 20; i++){
		s[0] = i / 10 + '0';
		s[1] = i % 10 + '0';
		out = fopen(s.c_str(), "w");
		long long a, b;
		a = rand(); b = rand();
		fprintf(out, "%lld %lld\n", a, b);
		fclose(out);
		out = fopen((s + ".a").c_str(), "w");
		fprintf(out, "%lld\n", a - b);
		fclose(out);
	}
}

