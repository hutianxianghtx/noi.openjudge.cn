#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char a[100][100];
int vis[100],ans,n,k;

int Backtrack(int cur,int num) {
	if(num>k) {
		ans++;
		return 1;
	} else {
		for(int i=cur; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(a[i][j]=='#'&&vis[j]==0) {
					vis[j]=1;
					Backtrack(i+1,num+1);
					vis[j]=0;
				}
			}
		}
	}
}
int main() {
	while(scanf("%d%d",&n,&k)!=EOF) {
		memset(vis,0,sizeof(0));
		if(n==-1&&k==-1) break;
		for(int i=0; i<n; i++) {
			scanf("%s",a[i]);
		}

		ans=0;
		Backtrack(0,1);
		printf("%d\n",ans);
	}
	return 0;
}
