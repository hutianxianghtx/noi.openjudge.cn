#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char mp[110][110];
int ha,la,hb,lb;
bool can;

void dfs(int x,int y) {
	if(can || mp[x][y]=='#') return;
	if(x==hb && y==lb) {
		can=true;
		return;
	}
	mp[x][y]='#';
	if(x>0 ) {
		dfs(x-1,y);
	} 
	if(y>0) {
		dfs(x,y-1);
	} 
	if(x<n-1) {
		dfs(x+1,y);
	} 
	if(y<n-1) {
		dfs(x,y+1);
	}
//	mp[x][y]='.';
}

int main() {
	int k;
	scanf("%d",&k);
	while(k--) {
		scanf("%d",&n);
		getchar();
		memset(mp,'#',sizeof(mp));
		can=false;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) scanf("%c",&mp[i][j]);
			getchar();
		}
		scanf("%d%d%d%d",&ha,&la,&hb,&lb);
		
		dfs(ha,la);
		
		if(can) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
