/*
This code is written by 胡元帅
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;
#define MAXR 210
#define MAXC 210

int R,C;
char map[MAXR][MAXC];
int sx,sy,ex,ey;
int mintime;

void dfs(int x,int y,int time) {
	if(time>=mintime) return;
	
	if(x==ex && y==ey) {
		if(time<mintime) mintime=time;
		return;
	}
	
	if(map[x][y]=='#') return;
	
	map[x][y]='#';
	dfs(x-1,y,time+1);
	dfs(x+1,y,time+1);
	dfs(x,y-1,time+1);
	dfs(x,y+1,time+1);
	map[x][y]='.';
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(map,'#',sizeof(map));
		mintime=INT_MAX;
		
		scanf("%d%d",&R,&C);
		for(int i=1;i<=R;i++) {
			getchar();
			for(int j=1;j<=C;j++) {
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S') {
					sx=i;
					sy=j;
				} else if(map[i][j]=='E') {
					ex=i;
					ey=j;	
				}
			}
		}
		
//		for(int i=1;i<=R;i++) {
//			for(int j=1;j<=C;j++) {
//				printf("%c ",map[i][j]);
//			}
//			printf("\n");
//		}
		
		dfs(sx,sy,0);
		
		if(mintime==INT_MAX) printf("oop!\n");
		else printf("%d\n",mintime);
	}
	return 0;
}
