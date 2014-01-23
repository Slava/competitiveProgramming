#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

int a[] = {4, 5, 2, 33, 102, 355};

/* START */
int main (){
	sort(a, a + 6);
	do{
		for (int i = 0; i < 6; i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}while(next_permutation(a, a + 6));
	return 0;
}
