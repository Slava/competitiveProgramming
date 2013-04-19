#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > ans;
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i=a%n, j=b%n; i||j; i+=a, j+=b, i%=n, j%=n)
		ans.push_back(make_pair(i,j));
	ans.push_back(make_pair(0,0));
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	printf("%d\n", ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
