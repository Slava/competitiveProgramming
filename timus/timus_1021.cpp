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

set<int>Y;
int n, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); Y.insert(x);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); 
		if (Y.find(10000 - x) != Y.end()) {
			puts("YES"); return 0;
		}
	}
	puts("NO");
	return 0;
}
