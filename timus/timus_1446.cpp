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

map<string,int> dic;
vector<string> v[4];
string s, t;
char buff[200];
int n;
int main() {
	scanf("%d", &n);gets(buff);
	dic["Slytherin"] = 0;
	dic["Hufflepuff"] = 1;
	dic["Gryffindor"] = 2;
	dic["Ravenclaw"] = 3;
	for (int i = 0; i < n; i++) {
		gets(buff); s = buff;
		gets(buff); t = buff;
		v[dic[t]].push_back(s);
	}
	printf("Slytherin:\n");
	for (int i = 0; i < v[0].size(); i++)
		printf("%s\n", v[0][i].c_str());
	printf("\nHufflepuff:\n");
	for (int i = 0; i < v[1].size(); i++)
		printf("%s\n", v[1][i].c_str());
	printf("\nGryffindor:\n");
	for (int i = 0; i < v[2].size(); i++)
		printf("%s\n", v[2][i].c_str());
	printf("\nRavenclaw:\n");
	for (int i = 0; i < v[3].size(); i++)
		printf("%s\n", v[3][i].c_str());

	return 0;
}
