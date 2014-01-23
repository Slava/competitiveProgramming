#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

string file = "01";
int main (){
	for (int i = 1; i <= 50; i++){
		long long a = rand(), b = (a * (a + 1))/2;
		file[0] = i / 10 + '0';
		file[1] = i % 10 + '0';
		FILE *out = fopen(file.c_str(), "w");
		fprintf(out, "%lld", a);
		fclose(out);
		out = fopen((file + ".a").c_str(), "w");
		fprintf(out, "%lld", b);
		fclose(out);
	}
	return 0;
}

