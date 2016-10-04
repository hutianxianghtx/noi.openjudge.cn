#include <iostream>
#include <string.h>
using namespace std;

char map[22][22];
int cnt;

void dfs(int x,int y) {
	if(map[x][y]=='#') return;
	cnt++;
	map[x][y]='#';
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x+1,y);
	dfs(x,y-1);
}

int main() {
	int w,h;  //注意：w是列   h是行
	while(cin>>w>>h) {
		if(w==0 && h==0) break;
		cnt=0;
		memset(map,'#',sizeof(map));
		int si,sj;
		for(int i=1;i<=h;i++) {
			for(int j=1;j<=w;j++) {
				cin>>map[i][j];
  				if(map[i][j]=='@') si=i,sj=j;
			}
		}
		dfs(si,sj);
		cout<<cnt<<endl;
	}
	return 0;
}
