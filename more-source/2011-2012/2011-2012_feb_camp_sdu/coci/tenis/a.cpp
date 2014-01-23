#include <cstdio>
#include <cstdlib>
#include <cstring>

char s1[30], s2[30], buf[100500], *ptr;
int setsWonA, setsWonB;

bool playSet(bool can66) {
	int a = -1, b = -1;
	while ((*ptr) == ' ')
		ptr++;
	if (!(*ptr))return 0;
	while ((*ptr) >= 0 && (*ptr) <= '9') {
		if (a == -1) a = 0;
		a = a * 10 + (*ptr)-'0';
		ptr++;
	}
ptr++;
//	printf("ptr:'");puts(ptr);fflush(stdout);getchar();
	while ((*ptr) >= '0' && (*ptr) <= '9') {
		if (b == -1) b = 0;
		b = b * 10 + (*ptr)-'0';
		ptr++;
	}
//	printf("a=%d b=%d\n", a, b);
//	printf("ptr:'");puts(ptr);fflush(stdout);getchar();
	if (a < 0 || b < 0) return 0;
	if (a < 6 && b < 6) return 0;
	if (a == 6 && b == 7 && !can66)return 0;
	if (a == 7 && b == 6 && !can66)return 0;
	if (can66 && ((a==6&&b==7)||(a==7&&b==6)))
		goto asdf;
	if (a > b && a-2 < b)return 0;
	if (a < b && b-2 < a)return 0;
asdf:;
	if (a > b)
		setsWonA++;
	else if (b > a)
		setsWonB++;
	return 1;
}

int main() {
	gets(buf);
	sscanf(buf, "%s %s\n", s1, s2);
	int n, ok = 1;
	gets(buf);
	sscanf(buf, "%d\n",&n);
	for (int i = 0; i < n; i++) {
//		printf("i:%d\n", i);fflush(stdout);
		gets(buf); ptr = buf;
		setsWonA = setsWonB = 0;
		int cnt = 0;
		while(setsWonA != 2 && setsWonB != 2) {
			if (!(*ptr)) {
				ok = 0; break;
			}
		//	printf("now %d,%d go play\n", setsWonA, setsWonB);fflush(stdout);
			puts(ptr);
			ok &= playSet(cnt<2);
			cnt++;
		}
		ok &= !sscanf("%s", buf);
		if (!strcmp("federer", s1) && setsWonA == 2)
			ok = 0;
		if (!strcmp("federer", s2) && setsWonB == 2)
			ok = 0;
		if (ok)
			puts("da");
		else puts("ne");
	//	fflush(stdout);
	}
	return 0;
}

