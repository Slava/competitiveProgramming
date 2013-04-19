#include <cstdio>
#include <cstdlib>

int main() {
	for (int i = 0; i < 1000000; i++)
		printf("%c", rand() % 26 + 'a');
	return 0;
}
