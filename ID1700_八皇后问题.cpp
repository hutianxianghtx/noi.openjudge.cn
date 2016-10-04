#include <iostream>
#include <cstdio>
using namespace std;

int a[20],b[20],c[20],ans[10],cnt;

void print() {
	printf("No. %d\n",++cnt);
	for(int i=1;i<=8;i++) {
		for(int j=1;j<=8;j++) {
			if(ans[j]==i) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
}

void dfs(int i) {
	if(i>8) print();
	
	for(int j=1;j<=8;j++) {
		if(a[j]==0 && b[j+i]==0 && c[j-i+8]==0) {
			a[j]=b[j+i]=c[j-i+8]=1;
			ans[i]=j;
			dfs(i+1);
			a[j]=b[j+i]=c[j-i+8]=0;
		}
	}
}

int main() {
	dfs(1);
	return 0;
}
