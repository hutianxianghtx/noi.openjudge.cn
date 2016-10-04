#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char map[30][30];
int mt[30][30];
bool yes;

struct NODE {
	int x;
	int y;
};

void bfs(int sx,int sy) {
	queue<NODE> q;
	NODE p,r;
	p.x=sx,p.y=sy;
	q.push(p);
	
	while(!q.empty()) {
		p=q.front();
		q.pop();
		if(map[p.x][p.y]=='*') {
			yes=true;
			printf("%d\n",mt[p.x][p.y]);
			break;
		}
		map[p.x][p.y]='#';
		
		r.x=p.x-1,r.y=p.y;
		if(map[r.x][r.y]!='#') {
			mt[r.x][r.y]=mt[p.x][p.y]+1;
			q.push(r);
		}
		
		r.x=p.x,r.y=p.y+1;
		if(map[r.x][r.y]!='#') {
			mt[r.x][r.y]=mt[p.x][p.y]+1;
			q.push(r);
		}
		
		r.x=p.x+1,r.y=p.y;
		if(map[r.x][r.y]!='#') {
			mt[r.x][r.y]=mt[p.x][p.y]+1;
			q.push(r);
		}
		
		r.x=p.x,r.y=p.y-1;
		if(map[r.x][r.y]!='#') {
			mt[r.x][r.y]=mt[p.x][p.y]+1;
			q.push(r);
		}
	}
}

int main() {
	int m,n,sx,sy;
	while(scanf("%d%d",&m,&n)) {
		if(m==0 && n==0) break;
		
		memset(map,'#',sizeof(map));
		memset(mt,0,sizeof(mt));
		yes=false;
		getchar();
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@') {
					sx=i;
					sy=j;
				}
			}
			getchar();
		}
		
		bfs(sx,sy);
		
		if(!yes) printf("-1\n");
	}
	
	return 0;
}
