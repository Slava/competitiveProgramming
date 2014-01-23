#include <cstdio>

int main (int argv, char *argc[]){
	long long a, b, c, jury, cont;
	char s[30000];
	FILE 
		 *out = fopen(argc[3], "r"),
		 *ans = fopen(argc[2], "r");
	if(!ans){
		fprintf(stderr, "No jury answer\n");
		return 1;
	}
	fscanf(ans, "%lld", &jury);
	if (!out){
		fprintf(stderr, "No output file\n");
		return 1;
	}
	if (fscanf(out, "%lld%s", &cont, s) == 1){
		if (cont == jury){
			fprintf(stderr, "OK\n");
			return 0;
		}
		fprintf(stderr, "WA\n%lld instead of %lld\n", cont, jury);
		return 1;
	}
	else {
		fprintf(stderr, "wrong output format\n");
		return 1;
	}
}

