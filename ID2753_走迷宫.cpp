#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int r,c;
char map[50][50];
int cnt[50][50];

struct NODE {
	int x;
	int y;
};

void bfs() {
	queue<NODE> q;
	NODE p,z;
	p.x=p.y=1;
	q.push(p);
	
	while(!q.empty()) {
		p=q.front();
		q.pop();
		if(p.x==r && p.y==c) {
			printf("%d\n",cnt[p.x][p.y]);
			break;
		}
		map[p.x][p.y]='#';
		
		z.x=p.x-1,z.y=p.y;
		if(map[z.x][z.y]!='#') {
			cnt[z.x][z.y]=cnt[p.x][p.y]+1;
			q.push(z);
		}
		
		z.x=p.x,z.y=p.y+1;
		if(map[z.x][z.y]!='#') {
			cnt[z.x][z.y]=cnt[p.x][p.y]+1;
			q.push(z);
		}
		
		z.x=p.x+1,z.y=p.y;
		if(map[z.x][z.y]!='#') {
			cnt[z.x][z.y]=cnt[p.x][p.y]+1;
			q.push(z);
		}
		
		z.x=p.x,z.y=p.y-1;
		if(map[z.x][z.y]!='#') {
			cnt[z.x][z.y]=cnt[p.x][p.y]+1;
			q.push(z);
		}
	}
}

int main() {
	scanf("%d%d",&r,&c);
	
	memset(map,'#',sizeof(map));
	memset(cnt,0,sizeof(cnt));
	getchar();
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) scanf("%c",&map[i][j]);
		getchar();
	}
	
	cnt[1][1]=1;
	bfs();
	return 0;
}
