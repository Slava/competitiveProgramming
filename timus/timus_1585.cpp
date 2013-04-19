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

string s;
int n, a, b, c;
int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s[0] == 'E')a++;
		else if (s[0] == 'M')b++;
		else c++;
	}
	if (a > b && a > c) cout << "Emperor Penguin";
	else if (b > a && b > c) cout << "Macaroni Penguin";
	else cout << "Little Penguin";
	return 0;
}
