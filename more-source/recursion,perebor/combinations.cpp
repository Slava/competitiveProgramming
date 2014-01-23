// generate all combinations
// C(n,k)

#include <cstdio>
#include <algorithm>

using namespace std; 
int a[10], s;
int main (){
	for (int i = 6; i < 10; i++) {
		a[i] = 1;
	}
	do{
		for (int i = 0; i < 10; i++)
			if(a[i])
				printf("%d ", i + 1);
		puts("");s++;
	}while(next_permutation(a, a + 10));
	printf("%d\n", s);
	return 0;
}
