#include<iostream>
#include<cstdio>
using namespace std;

int ans;

void dfs(int& a, int& b, int cur) {
	if(a < b) swap(a, b);
	if(!b) {
		ans = cur^1;
		return;
	}
	if(a/b >= 2) {
		ans = cur;
		return;
	}
	a -= b;
	dfs(a, b, cur^1);
}

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b) && a) {
		dfs(a, b, 1);
		if(ans) printf("win\n");
		else printf("lose\n");
	}
	return 0;
}
