#include <cstdio>

int main (int argv, char *argc[]){
	long long a, b, c, jury, cont;
	char s[30000];
	FILE *in = fopen(argc[1], "r"),
		 *out = fopen(argc[3], "r"),
		 *ans = fopen(argc[2], "r");
	fscanf(in, "%lld%lld", &a, &b);
	fscanf(ans, "%lld", &jury);
	if ((c = a * b) != jury){
		fprintf(stderr, "Jury error\n");
		return 2;
	}
	if (!out){
		fprintf(stderr, "No output file\n");
		return 1;
	}
	if (fscanf(out, "%lld%s", &cont, s) == 1){
		if (cont == c){
			fprintf(stderr, "OK\n");
			return 0;
		}
		fprintf(stderr, "WA\n");
		return 1;
	}
	else {
		fprintf(stderr, "wrong output format\n");
		return 1;
	}
}

